#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    void reverseStr(string &s, int start, int end) {
        end--; // Make end point to the last character of the word.
        while (start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }

    string reverseWords(string s) {
        int start = 0;
        for (int end = 0; end <= s.length(); end++) {
            if (end == s.length() || s[end] == ' ') {
                reverseStr(s, start, end);
                start = end + 1;
            }
        }
        return s;
    }
};


int main() {
    string str = "Let's take LeetCode contest";
    Solution s;
    string newStr = s.reverseWords(str);
    for(auto c : newStr) {
        cout<<c;
    }
    cout<<endl;
    return 0;
}