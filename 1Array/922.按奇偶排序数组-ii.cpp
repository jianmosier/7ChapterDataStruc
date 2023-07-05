#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    void leftRight(vector<int>& array){
        int i = 0, j = 1;
        while(i<array.size() && j<array.size()){
            if(array[i]%2 == 0) {i++;i++;}
            else if(!(array[j]%2 == 0)) {j++;j++;}
            else{
                swap(array[i],array[j]);
                i++;
                i++;
                j++;
                j++;
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
    vector<int> inArray = {2,3};
    vector<int> outArray;
    outArray = s.sortArrayByParityII(inArray);
    for(int i = 0; i < outArray.size(); i++){
        printf("%d ", outArray[i]);
    }
}