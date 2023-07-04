#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    void leftRight(vector<int>& array, int m , int n){
        if (m >= n) return;
        int i = m, j = n;
        int pivot = array[m + rand()%(n - m + 1)];
        while(i<=j){
            while(array[i] < pivot) i++;
            while(array[j] > pivot) j--;
            if(i<=j){
                swap(array[i],array[j]);
                i++;
                j--;
            }
        }
        leftRight(array,m,j);
        leftRight(array,i,n);
    }
    vector<int> sortArray(vector<int>& nums) {
        leftRight(nums, 0, nums.size()-1);
        return nums;
    }
};



int main(){
    Solution s;
    vector<int> inNums = {6,8};
    vector<int> outNums = s.sortArray(inNums);
    for(int i = 0; i < outNums.size(); i++){
        printf("%d ", outNums[i]);
    }
}