#include<iostream>
#include<stdio.h>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> strInt = {{"M",1000},{"CM",900},{"D",500},{"CD",400},
                                             {"C",100},{"XC",90},{"L",50},{"XL",40},
                                             {"X",10},{"IX",9},{"V",5},{"IV",4},
                                             {"I",1}};
        int count = 0;
        for(int i = 0; i < s.length();) {
            if(i<s.length()-1 && strInt.count(s.substr(i,2))) {
                count += strInt[s.substr(i,2)];
                i += 2;
            }
            else {
                count += strInt[s.substr(i,1)];
                i++;
            }   
        }
        return count;
    }
};

int main() {
    Solution s;
    string str = "MCDVII";
    int num = s.romanToInt(str);
    cout<<num<<endl;
    return 0;
}