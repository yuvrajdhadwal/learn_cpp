#include <iostream>
#include <string>
#include <vector>

constexpr char deliminator{','};

auto split(const std::string& str) -> std::vector<std::string> {
    std::size_t pos{str.find(deliminator)};
    std::vector<std::string> out;

    std::size_t strStart{0};
    while (pos != std::string::npos) {
        out.push_back(str.substr(strStart, pos - strStart));
        strStart = pos + 1;
        pos = str.find(deliminator, pos + 1);
    }

    out.push_back(str.substr(strStart));
    return out;
}

auto main() -> int {
    for (const std::string& s : split("Hello, my name, Yuvraj, is unique, but also, not very, very "
                                      "unique at the same time. Confusing, isn't it?")) {
        std::cout << s << '\n';
    }
}
