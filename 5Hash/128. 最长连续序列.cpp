#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet(nums.begin(), nums.end());
        int maxLen = 0;
        for(auto num : hashSet) {
            if(!hashSet.count(num-1)) {
                int currentNum = num;
                int len = 1;
                while(hashSet.count(currentNum+1)) {
                    currentNum++;
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};

int main() {
    vector<int> vec = {2,3,5,7,9,34,2,1,56,32};
    Solution s;
    cout << s.longestConsecutive(vec) << endl;
    return 0;
}
