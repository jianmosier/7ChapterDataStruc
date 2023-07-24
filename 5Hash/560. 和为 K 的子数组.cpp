#include<iostream>
#include<unordered_map>
#include<vector>


using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSum;
        preSum[0] = 1;
        int sum_i = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum_i += nums[i];
            if (preSum.count(sum_i - k)) {            
                count += preSum[sum_i - k]; 
            }
            preSum[sum_i]++;
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2,3,4,3,0,0,0,0,2,2};
    int k = 7;
    int result = solution.subarraySum(nums, k);
    cout << "Number of subarrays equal to k: " << result << endl;
    return 0;
}