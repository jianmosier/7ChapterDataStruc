//力扣242
#include<iostream>
#include<map>
#include<stdio.h>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s1, string s2) {
        if(s1.length()!=s2.length()) return false;
        unordered_map<char, int> counts;
        for(int i = 0; i < s1.length(); i++) {
            counts[s1[i] - 'a']++;
            counts[s2[i] - 'a']--;
        }
        for(auto count : counts) {
            if(count.second != 0) return false;
        }
        return true;
    }
};

int main(){
    string s = "anagramt";
    string t = "nagaramt";
    Solution solution;
    bool result = solution.isAnagram(s, t);
    cout << result << endl;
    return 0;
}