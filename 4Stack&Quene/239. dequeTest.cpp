#include<iostream>
#include<vector>
#include<deque>
#include <cassert>

using namespace std;

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        if (nums.empty() || k <= 0) {
            return {};
        }

        std::vector<int> result;
        // 存储的是元素的索引
        std::deque<int> deq;

        for (int i = 0; i < nums.size(); ++i) {
            // 移除窗口之外的元素
            while (!deq.empty() && deq.back() < i - k + 1) {
                deq.pop_back();
            }

            // 移除比当前元素小的元素，因为它们不可能是最大的
            while (!deq.empty() && nums[i] >= nums[deq.front()]) {
                deq.pop_front();
            }

            deq.push_front(i);

            // 窗口形成后开始记录答案
            if (i >= k - 1) {
                result.push_back(nums[deq.back()]);
            }
        }

        return result;
    }
};

int main() {
    Solution s;

    // // 测试用例1
    // std::vector<int> nums1 = {1,3,-1,-3,5,3,6,7};
    // int k1 = 3;
    // std::vector<int> expected1 = {3,3,5,5,6,7};
    // assert(s.maxSlidingWindow(nums1, k1) == expected1);

    // // 测试用例2
    // std::vector<int> nums2 = {1, -1};
    // int k2 = 1;
    // std::vector<int> expected2 = {1, -1};
    // assert(s.maxSlidingWindow(nums2, k2) == expected2);

    // 测试用例3
    std::vector<int> nums3 = {7, 2, 4};
    int k3 = 2;
    std::vector<int> expected3 = {7, 4};
    assert(s.maxSlidingWindow(nums3, k3) == expected3);

    // 更多的测试用例 ...

    cout << "所有测试用例都通过了!" << endl;

    return 0;
}