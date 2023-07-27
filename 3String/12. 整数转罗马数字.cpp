#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    void toRoman(int base, int& num, char high, char mid, char low, string& s) {
        int count = num / base;
        num %= base;
        if(count >= 9) {
            s.push_back(low);
            s.push_back(high);      
        }
        else if(count >= 5) {
            s.push_back(mid);
            for(int i = count - 5; i > 0; i--) {
                s.push_back(low);
            }
        }
        else if(count == 4){
            s.push_back(low);
            s.push_back(mid);
        }
        else {
            for(int i = count; i > 0; i--) {
                s.push_back(low);
            }
        }
    }
    string intToRoman(int num) {
        string s = "";
        toRoman(1000, num, ' ', ' ', 'M', s);
        toRoman(100, num, 'M', 'D', 'C', s);
        toRoman(10, num, 'C', 'L', 'X', s);
        toRoman(1, num, 'X', 'V', 'I', s);
        return s;
    }
};

int main() {
    int num = 3876;
    Solution s;
    string str = s.intToRoman(num);
    for(auto st : str) {
        cout<<st;
    } 
    return 0;
}