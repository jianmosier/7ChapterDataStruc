#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,vector<string>> intStr = {{"2",{"a","b","c"}},
                                                    {"3",{"d","e","f"}},
                                                    {"4",{"g","h","i"}},
                                                    {"5",{"j","k","l"}},
                                                    {"6",{"m","n","o"}},
                                                    {"7",{"p","q","r","s"}},
                                                    {"8",{"t","u","v"}},
                                                    {"9",{"w","x","y","z"}}};
        vector<vector<string>> vecArray;    
        vector<string> outStr;                                        
        for(int i = 0; i < digits.length(); i++) {
            vecArray.push_back(intStr[digits.substr(i,1)]);
        } 
        if(digits.length() == 0) outStr = " ";
        else if(digits.length() == 1) {
            return vecArray[0];
        } 
        else if(digits.length() == 2) {
            for(int i = 0; i<vecArray[0].size(); i++) {
                for(int j = 0; j <  vecArray[1].size(); j++) {
                    outStr.push_back(vecArray[0][i] + vecArray[1][k]);
                }
            }
        }
        else if(digits.length() == 3) {
            for(int i = 0; i<vecArray[0].size(); i++) {
                for(int j = 0; j <  vecArray[1].size(); j++) {
                    for(int m = 0; m < vecArray[2].size(); m++) {
                        outStr.push_back(vecArray[0][i] + vecArray[1][k] + vecArray[2][m]);  
                    }
                }
            }
        }
        else if(digits.length() == 3) {
            for(int i = 0; i<vecArray[0].size(); i++) {
                for(int j = 0; j <  vecArray[1].size(); j++) {
                    for(int m = 0; m < vecArray[2].size(); m++) {
                        for(int n = 0; n < vecArray[3].size(); n++) {
                            outStr.push_back(vecArray[0][i] + vecArray[1][k] + vecArray[2][m] + vecArray[3][n]);  
                        }  
                    }
                }
            }
        }    
        return outStr;                         
    }
};

int main() {
    
}