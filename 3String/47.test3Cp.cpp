//The idea of the backtracking algorithm
#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>

using namespace std;

// 定义一个Solution类
class Solution {
private:
    // 定义了三个私有变量
    vector<vector<int>> res;  // 存储结果的二维数组
    vector<int> path;         // 保存当前的排列路径
    vector<bool> used;        // 一个布尔数组，用来标记哪些数字已经在当前排列路径中使用过了

    // 定义一个私有的backtrack函数，它是实现回溯算法的核心
    void backtrack(vector<int>& nums) {
        // 当前排列路径的长度等于输入数组的长度，说明找到了一个排列
        if (path.size() == nums.size()) {
            res.push_back(path);  // 将该排列添加到结果中
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            // 跳过重复数字：只有当当前数字和前一个数字相等，并且前一个数字尚未使用时，我们才跳过
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            if (!used[i]) {  // 如果当前数字尚未使用
                used[i] = true;          // 标记为已使用
                path.push_back(nums[i]); // 将数字添加到当前排列路径中
                backtrack(nums);         // 递归进一步查找
                // 下面两行是回溯部分，撤销选择，为寻找其他可能的排列做准备
                used[i] = false;
                path.pop_back();
            }
        }
    }

public:
    // 主函数，用于生成所有的唯一排列
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 如果输入数组为空，则直接返回空的结果
        if (nums.empty()) return res;
        // 对数组进行排序，这是为了后面方便跳过重复数字
        sort(nums.begin(), nums.end());
        // 初始化used数组的大小和值
        used.resize(nums.size(), false);
        // 从第一个数字开始回溯查找所有排列
        backtrack(nums);
        // 返回最终的结果
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