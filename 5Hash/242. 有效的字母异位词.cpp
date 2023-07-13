//力扣242
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        vector<int> counts(26, 0);
        for(int i = 0; i < s.size(); i++) {
            counts[s[i]-'a']++;
            counts[t[i]-'a']--;
        }
        for(auto count : counts) {
            if (count != 0) return false;
        }
        return true;
    }
};

int main(){
    string s = "anagrams";
    string t = "nagaramt";
    Solution solution;
    bool result = solution.isAnagram(s, t);
    cout << result << endl;
    return 0;
}