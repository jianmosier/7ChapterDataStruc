#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;
    vector<int> path;

    void backTrack(vector<int> nums) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            if(!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                backTrack(nums);
                used[i] = false;
                path.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> nums) {
        if(nums.empty()) return res;
        sort(nums.begin(), nums.end());
        used.resize(nums.size(), false);
        backTrack(nums);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,1,1};
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