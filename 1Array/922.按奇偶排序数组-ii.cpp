#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    bool inPlace(int value, int place, int len){
        if(place >= len || place < 0) return false;
        if(place == 0){
            if(value == 0) return true;
            return (value%2 == 0) ? true : false;
        }
        else{
            if(value == 0){
                return (place%2 == 0) ? true : false;
            }
            else{
                if(value%2 == 0){
                    return (place%2 == 0) ? true : false;
                }
                else{
                    return (place%2 == 0) ? false : true;
                }
            }
        }
    }
    void leftRight(vector<int>& array){
        int n = array.size()/2;
        int i = 0, j = n - i;
        while(i<n){
            while(inPlace(array[2*i],2*i,2*n)) {i++;}
            while(inPlace(array[2*j - 1],2*j - 1,2*n)) {j--;}
            if(i<n){
                swap(array[2*i],array[2*j - 1]);
                i++;
                j--;
            }
        }
    }
    vector<int> sortArrayByParityII(vector<int>& nums) {
        leftRight(nums);
        return nums;
    }
};

int main(){
    Solution s;
    vector<int> inArray = {4,5,2,1,9,8,7,3};
    vector<int> outArray;
    outArray = s.sortArrayByParityII(inArray);
    for(int i = 0; i < outArray.size(); i++){
        printf("%d ", outArray[i]);
    }
}