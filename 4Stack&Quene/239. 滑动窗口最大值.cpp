#include<iostream>
#include<vector>
#include<climits>

using namespace std;

//暴力解法

class Solution {
private:
    vector<int> vec;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size() - k + 1; i++) {
            int maxNum = INT_MIN;
            for(int j = i; j < i + k; j++) {
                if(maxNum < nums[j]) maxNum = nums[j];
            }
            vec.push_back(maxNum);
        }
        return vec;
    }
};