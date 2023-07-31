#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        
        unordered_map<char,vector<string>> intStr = {{'2',{"a","b","c"}},
                                                    {'3',{"d","e","f"}},
                                                    {'4',{"g","h","i"}},
                                                    {'5',{"j","k","l"}},
                                                    {'6',{"m","n","o"}},
                                                    {'7',{"p","q","r","s"}},
                                                    {'8',{"t","u","v"}},
                                                    {'9',{"w","x","y","z"}}};
        vector<string> outStr = {""};
        for(char digit : digits) {
            vector<string> temp;
            for(string str : outStr) {
                for(string letter : intStr[digit]) {
                    temp.push_back(str + letter);
                }
            }
            outStr.swap(temp);
        }
        return outStr;
    }
};

int main() {
    Solution s;
    string  str  =  "46";
    vector<string> newStr = s.letterCombinations(str);
    for(auto strin : newStr) {
        cout<<strin<<" ";
    }
    return 0;
}
