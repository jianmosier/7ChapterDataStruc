#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> pertutateQueen(vector<int> nums) {
        set<vector<int>> result;
        sort(nums.begin(), nums.end());
        do{
            result.insert(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return vector<vector<int>>(result.begin(), result.end());
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,1,1,2,2};
    vector<vector<int>> outResult = s.pertutateQueen(nums);
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