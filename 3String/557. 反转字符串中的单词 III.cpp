#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    void reverseStr(string &str, int begin, int end) {
        end--;
        while(begin < end) {
            int temp = str[begin];
            str[begin] = str[end];
            str[end] = temp;
            begin++;
            end--;
        }
    }
    string reverseChar(string s) {
        int begin = 0, end = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                end = i;
                reverseStr(s, begin, end);
                begin = i + 1;
            }
        }
        reverseStr(s, begin, s.length());
        return s;
    }
};

int main() {
    string str = "Let's take LeetCode contest";
    Solution s;
    string newStr = s.reverseChar(str);
    for(auto c : newStr) {
        cout<<c;
    }
    cout<<endl;
    return 0;
}