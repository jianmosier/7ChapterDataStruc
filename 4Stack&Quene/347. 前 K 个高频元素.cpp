#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
private:
    unordered_map <int, int> uMap;
    vector <int> tmp;
    vector <int> rst;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            uMap[nums[i]]++;
        }
        for (auto pair : uMap) {
            tmp.push_back(pair.second);
        }
        sort(tmp.begin(), tmp.end());
        for (int j = tmp.size() - 1; j >= tmp.size() - k; j--) {
            for(auto pair : uMap) {
                if(pair.second == tmp[j]) rst.push_back(pair.first);
            }
        }
        return rst;
    }
};