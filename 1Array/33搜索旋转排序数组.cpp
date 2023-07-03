#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {

public:
    int result = 0;
    int mid = 0;
    int findOrder(int m, int n, vector<int>& nums, int target){
        if(m == n){
            if(target == nums[m]) return m;
            else return -1;
        }
        mid = (m+n)/2;
        if(target<=nums[mid]){
            result = findOrder(m,mid,nums,target);
        }
        else{
            result = findOrder(mid+1,n,nums,target);
        }
        return result;
    }
    int findDisOrder(int m, int n, vector<int>& nums, int target){
        if(m == n){
            if(target == nums[m]) return m;
            else return -1;
        }
        mid = (m+n)/2;
        if(nums[m] <= nums[mid]){
            if(nums[m] <= target && target <= nums[mid]){
                result = findOrder(m,mid,nums,target);
            }
            else{
                result = findDisOrder(mid+1,n,nums,target);
            }
        }
        else{
            if(nums[mid+1] <= target && target <= nums[n]){
                result = findOrder(mid+1,n,nums,target);
            }
            else{
                result = findDisOrder(m,mid,nums,target);
            }   
        }
        return result;
    }
    int search(vector<int>& nums, int target) {
        int len = nums.size(), i = 0;
        return  findDisOrder(i,len-1,nums, target);
    }
};

int main(){

    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int rst = s.search(nums, target);
    cout<<rst<<endl;        
    return 0;
}