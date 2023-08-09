#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> uMap;
    vector<int> rst;

public:
    vector<int> dfsov (vector<int> nums, int k) {
        for(auto num : nums) {
            uMap[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(auto [num, freq] : uMap) {
            pq.push({-freq, num});
            while(pq.size() > k) {
                pq.pop();
            }
        }
        while(!pq.empty()) {
            rst.push_back(pq.top().second);
            pq.pop();
        }
        return rst;
    }
};