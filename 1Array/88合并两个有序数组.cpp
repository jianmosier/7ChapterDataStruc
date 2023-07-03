#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        for(i = m-1, j = n-1; i >= 0 && j >= 0;){
            if(nums1[i] <= nums2[j]){
                nums1[i+j+1] = nums2[j];
                j--;
            }
            else{
                nums1[i+j+1] = nums1[i];
                i--;
            }
        }
        if(j >= 0){
            for(; j >= 0; j--){
                nums1[j] = nums2[j];
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2,4,0,0,0};
    vector<int> nums2 = {3,5,6};
    int m = 3, n = 3;
    s.merge(nums1,m,nums2,n);
    for(int i = 0; i < m+n; i++){
        printf("%d ",nums1[i]);
    }
    return 0;
}