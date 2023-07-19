#include <unordered_map>
#include <string>
#include <iostream>

int main() {
    // 创建一个空的散列表
    std::unordered_map<std::string, int> hashtable;
    std::unordered_map<std::string, int> hashtableOne;

    // 插入键值对
    hashtable["a"] = 4;
    hashtable["你好"] = 5;
    hashtable["ing"] = 6;

    hashtableOne = {
        {"b",4},
        {"world",5},
        {"哈哈",6}
    };

    // 输出键值对
    for (const auto &pair : hashtableOne) {
        std::cout << "键：" << pair.first << ", 值：" << pair.second << std::endl;
    }

    return 0;
}
