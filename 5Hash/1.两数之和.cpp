//1.两数之和
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> addNum(vector<int> vec, int target) {
        unordered_map<int, int> preSum;
        vector<int> result;
        for (int i = 0; i < vec.size(); i++) {
            if (preSum.count(target - vec[i])) {
                result.push_back(preSum[target - vec[i]]);
                result.push_back(i);
                return result;
            }
            preSum[vec[i]] = i;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> vec = {1,2,3,4,3,0,0,0,0,2,2};
    int target = 7;
    vector<int> result = solution.addNum(vec, target);
    cout << "The index of the two numbers: " << result[0] << " " << result[1] << endl;
    return 0;
}