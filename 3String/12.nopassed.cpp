#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    void toRoman(int base, int& num, string& high, string& mid, string& low, string& s) {
        int count = num / base;
        if(count >= 9) {
            s.push_back(low + high);
            num = num % 10;
        }
        else if(count < 9 && count >= 5) {
            s.push_back(mid);
            while(count-5) {
                s.push_back(low);
                count--;
            }
            num = num % 10;
        }
        else if(count == 4){
            s.push_back(low + mid);
            num = num % 10;
        }
        else {
            while(count) {
                s.push_back(low);
                count--;
            }
            num = num % 10;
        }
    }
    string intToRoman(int num) {
        string s = "";
        if(num / 1000) {
            int count = num / 1000;
            while(count) {
                s.push_back("M");
                count--;
            }
            num = num % 10;
        }
        if(num / 100) {
            toRoman(100, num, 'M', 'D', 'C', s);
        }
        if(num / 10) {
            toRoman(10, num, 'C', 'L', 'X', s);
        }
        toRoman(1, num, 'X', 'V', 'I', s);
        return s;
    }
};