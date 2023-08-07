//The idea of the backtracking algorithm
#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    void backtrack(int begin, vector<int>& nums, set<vector<int>>& result) {
        if (begin == nums.size()) {
            result.insert(nums);
            return;
        }
        
        unordered_set<int> seen;
        for (int i = begin; i < nums.size(); i++) {
            if (seen.count(nums[i])) continue;
            seen.insert(nums[i]);
            swap(nums[begin], nums[i]);
            backtrack(begin + 1, nums, result);
            swap(nums[begin], nums[i]);  // 撤销动作，恢复原状，以便进行下一次的交换操作
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> result;
        backtrack(0, nums, result);
        return vector<vector<int>>(result.begin(), result.end());
    }
};


int main() {
    Solution s;
    vector<int> nums = {3,1,2,1};
    vector<vector<int>> outResult = s.permuteUnique(nums);
    cout<<"[";
    for(int result = 0; result < outResult.size(); result++) {
        cout<<"[";
        for(int elem=0; elem < outResult[result].size(); elem++) {
            cout<<outResult[result][elem];
            if(elem < outResult[result].size() - 1) cout<<", ";
        }
        cout<<"]";
        if(result < outResult.size() - 1) cout<<", ";
    }
    cout<<"]";
    return 0;
}