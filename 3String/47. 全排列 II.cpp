//47.全排列 II
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> resultSet;
        sort(nums.begin(), nums.end());
        do {
            resultSet.insert(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        
        return vector<vector<int>>(resultSet.begin(), resultSet.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, 2, 2};
    vector<vector<int>> result = sol.permuteUnique(nums);

    // 输出结果
    cout << "[";
    for (const auto& perm : result) {
        cout << "[";
        for (int i = 0; i < perm.size(); ++i) {
            cout << perm[i];
            if (i < perm.size() - 1) {
                cout << ", ";
            }
        }
        cout << "], ";
    }
    cout << "]" << endl;

    return 0;
}