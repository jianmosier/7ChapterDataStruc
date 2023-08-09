#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // Pair: (-frequency, number) [We use negative frequency to make it a max-heap based on frequency]
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

        for (auto [num, freq] : freqMap) {
            pq.push({-freq, num});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};

void test() {
    Solution s;

    // 测试用例1
    vector<int> nums1 = {4,4,4,5,5,3,2,2};
    int k1 = 2;
    vector<int> result1 = s.topKFrequent(nums1, k1);
    sort(result1.begin(), result1.end());
    assert(result1 == vector<int>({1,2}));

    // 测试用例2
    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> result2 = s.topKFrequent(nums2, k2);
    assert(result2 == vector<int>({1}));

    // 更多测试用例 ...

    cout << "所有测试用例都通过了!" << endl;
}

int main() {
    test();
    return 0;
}
