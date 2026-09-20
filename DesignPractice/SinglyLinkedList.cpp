#include <iostream>
#include <memory>
#include <vector>

template <typename T, typename U>
struct SinglyLinkedListNode {
    T key;
    U value;
    std::unique_ptr<SinglyLinkedListNode<T, U>> next;

    SinglyLinkedListNode(T key, U value) : key{key}, value{value} {}
};

template <typename T, typename U>
class SinglyLinkedList {
   private:
    using Node = SinglyLinkedListNode<T, U>;
    std::unique_ptr<Node> head;

   public:
    SinglyLinkedList() : head{std::make_unique<Node>(T{}, U{})} {}

    SinglyLinkedList(const std::vector<T>& keys, U value) : SinglyLinkedList{} {
        for (auto rit{keys.rbegin()}; rit != keys.rend(); ++rit) {
            pushFront(*rit, value);
        }
    }

    ~SinglyLinkedList() {
        while (head) {
            head = std::move(head->next);
        }
    }

    void printList() const {
        std::cout << "Singly Linked List: \n";
        for (const Node* curr{head->next.get()}; curr; curr = curr->next.get()) {
            std::cout << curr->key << ", " << curr->value << '\n';
        }
    }

    void pushFront(T key, U value) {
        auto node{std::make_unique<Node>(key, value)};
        node->next = std::move(head->next);
        head->next = std::move(node);
    }

    auto insertAfter(Node* node, T key, U value) -> bool {
        if (node == nullptr) {
            return false;
        }
        auto newNode{std::make_unique<Node>(key, value)};
        newNode->next = std::move(node->next);
        node->next = std::move(newNode);
        return true;
    }

    auto getNodeAtIndex(std::size_t index) -> Node* {
        Node* curr{head->next.get()};
        for (std::size_t i{0}; curr && i < index; ++i) {
            curr = curr->next.get();
        }

        return curr;
    }

    auto removeAfter(Node* node) -> std::unique_ptr<Node> {
        if (node == nullptr || node->next == nullptr) {
            return nullptr;
        }

        std::unique_ptr<Node> removedNode{std::move(node->next)};
        node->next = std::move(removedNode->next);
        return removedNode;
    }

    void reverseList() {
        std::unique_ptr<Node> prev {nullptr};
        std::unique_ptr<Node> curr {std::move(head->next)};

        while (curr) {
            std::unique_ptr<Node> nextNode {std::move(curr->next)};
            curr->next = std::move(prev);
            prev = std::move(curr);
            curr = std::move(nextNode);
        }

        head->next = std::move(prev);
    }
};

auto main() -> int {
    SinglyLinkedList<int, int> sll;
    sll.printList();

    std::vector<int> ints{1, 2, 3, 4};
    SinglyLinkedList<int, int> sll2{ints, -1};
    sll2.printList();

    sll2.insertAfter(sll2.getNodeAtIndex(2), 3, 4);
    sll2.printList();

    sll2.removeAfter(sll2.getNodeAtIndex(2));
    sll2.printList();

    sll2.reverseList();
    sll2.printList();

    return 0;
}
