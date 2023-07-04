#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> leftRight(vector<int>& array) {
        if(array.size() <= 1) return array;
        vector<int> la, ra, tempA;
        for(int i = 1; i < array.size(); i++){
            if(array[i] < array[0]){
                la.push_back(array[i]);
            }
            else if(array[i] > array[0]){
                ra.push_back(array[i]);
            }
            else{
                tempA.push_back(array[i]);
            }
        }
        la = leftRight(la);
        ra = leftRight(ra);
        tempA = leftRight(tempA);
        la.push_back(array[0]);
        la.insert(la.end(),tempA.begin(),tempA.end());
        la.insert(la.end(),ra.begin(),ra.end());
        
        return la;
    }
    vector<int> sortArray(vector<int>& nums) {
        return leftRight(nums);
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,1,1,2,0,0};
    vector<int> result = s.sortArray(nums);
    for(int i = 0; i<result.size(); i++){
        printf("%d ",result[i]);
    }
    return 0;
}