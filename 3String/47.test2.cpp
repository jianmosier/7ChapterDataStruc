//The idea of the backtracking algorithm
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solutions {
public:
    void swapAll(int begin, int end, vector<int>& nums, set<vector<int>>& result) {
        for(int i = begin; i < end; i++) {
            vector<int> temp = nums;
            int tempBegin = begin;
            if(end - begin <= 2) {
                result.insert(nums);
                swap(nums[begin], nums[end - 1]);
                result.insert(nums);
                return;
            }
            else {
                swap(nums[begin], nums[i]);
                result.insert(nums);
                begin++;
                swapAll(begin, end, nums, result);
            }
            nums = temp;
            begin = tempBegin;
        }
    }
    vector<vector<int>> pertutaQueen(vector<int> nums) {
        set<vector<int>> result;
        swapAll(0, nums.size(), nums, result);
        return vector<vector<int>>(result.begin(), result.end());
    }
};

int main() {
    Solutions s;
    vector<int> nums = {3,1,2,1};
    vector<vector<int>> outResult = s.pertutaQueen(nums);
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