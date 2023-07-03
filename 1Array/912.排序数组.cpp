#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i<len-1; i++){
            for(int j = i+1; j<len; j++){
                if(nums[i]>nums[j]){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        return nums;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,2,3,1};
    vector<int> result = s.sortArray(nums);
    for(int i = 0; i<result.size(); i++){
        printf("%d ",result[i]);
    }
    return 0;
}