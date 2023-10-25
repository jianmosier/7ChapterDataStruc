#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // 将所有单词放入一个集合中，便于后续快速查找
    unordered_set<string> dict(wordList.begin(), wordList.end());
    // 如果结束单词不在字典中，则无法转换，直接返回 0
    if (!dict.count(endWord)) {
        return 0;
    }
    
    queue<string> q;
    q.push(beginWord);

    int ladder = 1; // ladder 代表当前的“梯子”长度
    while (!q.empty()) {
        int n = q.size();
        // 对当前队列中的所有单词进行一次遍历
        for (int i = 0; i < n; i++) {
            string word = q.front();
            q.pop();
            // 检查是否可以转换到 endWord
            if (word == endWord) 
                return ladder; // 成功到达，返回梯子长度
            dict.erase(word); // 从字典中移除已经尝试过的单词
            // 尝试当前单词的所有可能的变种
            for (int j = 0; j < word.size(); j++) {
                char c = word[j];
                for (int k = 0; k < 26; k++) {
                    word[j] = 'a' + k; // 改变一个字符
                    // 如果新词在字典中，则加入到处理队列中
                    if (dict.count(word)) q.push(word);
                }
                word[j] = c; // 恢复原状，为下一个改变做准备
            }
        }
        ladder++; // 增加“梯子”的长度
    }
    return 0; // 如果没有成功的转换序列，返回 0
}

// 主函数，用于测试
int main() {
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit";
    string endWord = "cog";
    cout << "Shortest transformation is length = " << ladderLength(beginWord, endWord, wordList);
    return 0;
}
