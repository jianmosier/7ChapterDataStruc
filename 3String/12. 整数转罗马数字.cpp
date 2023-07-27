#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> values {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string result;
        for (int i = 0; i < values.size() && num >= 0; i++) {
            while (values[i] <= num) {
                num -= values[i];
                result += symbols[i];
            }
        }
        return result;
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