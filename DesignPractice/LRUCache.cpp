#include <memory>
#include <unordered_map>

// If we wanted to make this multi-threaded support there are two options
// Either we parition the cache and create a lock per partition, this creates less pressure on a
// single lock for the entire cache Use Approx LRU with Clock Algorithm!

class LRUCache {
   private:
    struct Node {
        int key;
        int val;
        std::unique_ptr<Node> next;
        Node* prev{};

        Node(int key, int val) : key{key}, val{val}, next{nullptr},  {}
    };

    const int capacity;
    std::unique_ptr<Node> lru;
    Node* mru{};
    std::unordered_map<int, Node*> nodes;

    auto appendMostRecent(std::unique_ptr<Node> node) -> Node* {
        Node* prev = mru->prev;
        node->prev = prev;
        node->next = std::move(prev->next);
        prev->next = std::move(node);
        mru->prev = prev->next.get();
        return prev->next.get();
    }

    auto removeNode(Node* node) -> std::unique_ptr<Node> {
        Node* prev = node->prev;
        std::unique_ptr<Node> owned = std::move(prev->next);
        owned->next->prev = prev;
        prev->next = std::move(owned->next);
        return owned;
    }

   public:
    LRUCache(int capacity) : capacity{capacity}, lru{std::make_unique<Node>(-1, -1)} {
        lru->next = std::make_unique<Node>(-1, -1);
        mru = lru->next.get();
        mru->prev = lru.get();
    }

    ~LRUCache() {
        // iterative instead of recrusive deletion of the entire list, avoids stack overflow for
        // massive lists
        while (lru) {
            lru = std::move(lru->next);
        }
    }

    int get(int key) {
        auto it{nodes.find(key)};
        if (it == nodes.cend()) {
            return -1;
        }

        std::unique_ptr<Node> node{removeNode(it->second)};
        return appendMostRecent(std::move(node))->val;
    }

    void put(int key, int value) {
        auto it{nodes.find(key)};
        if (it != nodes.cend()) {
            std::unique_ptr<Node> node{removeNode(it->second)};
            node->val = value;
            appendMostRecent(std::move(node));
            return;
        }

        if (static_cast<int>(nodes.size()) == capacity) {
            std::unique_ptr<Node> node{removeNode(lru->next.get())};
            nodes.erase(node->key);
        }

        nodes[key] = appendMostRecent((std::make_unique<Node>(key, value)));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
