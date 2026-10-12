// Given a chat of messages (vector of strings), and a set of chat members (vector of strings),
// return a list of pairs signifying chat member name and how many messages they were mentioned in.
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct MemberMentions {
    std::string memberName;
    int mentionCount;
};

constexpr char mentionMarker{'@'};

void updateMentions(const std::string& message, std::size_t pos,
                    std::unordered_set<std::string>& mentions) {
    if (pos != 0 and message[pos - 1] != ' ') {
        // return early if not valid mention
        return;
    }

    std::size_t currMentionStart{pos + 1};
    for (std::size_t i{pos + 1}; i <= message.size(); ++i) {
        if (i == message.size() or message[i] == ' ') {
            mentions.insert(message.substr(currMentionStart, i - currMentionStart));
            break;
        }

        if (message[i] == ',') {
            mentions.insert(message.substr(currMentionStart, i - currMentionStart));
            currMentionStart = i + 1;
        }
    }
}

auto countMentions(const std::vector<std::string>& messages,
                   const std::vector<std::string>& members) -> std::vector<MemberMentions> {
    std::unordered_map<std::string, int> messageMentions;

    for (const std::string& message : messages) {
        // find who was mentioned here
        std::unordered_set<std::string> mentions;
        std::size_t pos{message.find(mentionMarker)};

        while (pos != std::string::npos) {
            updateMentions(message, pos, mentions);
            pos = message.find(mentionMarker, pos + 1);
        }

        // update message mentions
        for (const std::string& mention : mentions) {
            ++messageMentions[mention];
        }
    }

    std::vector<MemberMentions> out;
    out.reserve(members.size());
    for (const std::string& member : members) {
        out.push_back({.memberName = member, .mentionCount = messageMentions[member]});
    }
    return out;
}

auto main() -> int {
    std::vector<std::string> messages{
        "Hey @Yuvraj,Sanat what are you up to?",
        "Nothing @Amy",
        "@Anshul what is up?",
        "Nothing @Sanat just rock clim@bing and working out. How about you @Sanat",
        "The sky! @",
        "Wow @Tumonov",
    };
    std::vector<std::string> members{"Yuvraj", "Amy", "Sanat", "Anshul", "", "Daniel"};
    std::vector<int> mentions{1, 1, 2, 1, 1, 0};

    auto out{countMentions(messages, members)};

    for (std::size_t i{0}; i < members.size(); ++i) {
        const auto& [member, mentionFreq] = out.at(i);
        std::cout << "Member: " << member << " was mentioned in the chat " << mentionFreq
                  << " times.\n";
        assert(member == members.at(i));
        assert(mentionFreq == mentions.at(i));
    }
}
