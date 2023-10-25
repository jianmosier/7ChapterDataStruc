#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_set>


using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        int l = beginWord.length();
        int step = 0;

        while (!q1.empty() && !q2.empty()) {
            ++step;

            // 为了优化，总是从较小的队列进行扩展
            if (q1.size() > q2.size())
                std::swap(q1, q2);

            unordered_set<string> q;

            for (string w : q1) {
                for (int i = 0; i < l; ++i) {
                    char ch = w[i];
                    for (int j = 'a'; j <= 'z'; ++j) {
                        w[i] = j;
                        if (q2.count(w)) return step + 1; // 找到最短路径
                        if (!dict.count(w)) continue; // 不在字典中，忽略
                        dict.erase(w); // 从字典中移除
                        q.insert(w); // 添加到下一层的队列中
                    }
                    w[i] = ch; // 恢复单词状态
                }
            }

            std::swap(q, q1); // 为下一轮做准备
        }
        return 0; // 如果没有找到，返回 0
    }
};