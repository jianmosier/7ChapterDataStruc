#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int isPnum(int n) {
        vector<bool> vec(n,true);
        int count = 0;
        for(int i = 2; i<n; i++) {
            if(vec[i]) {
                count++;
                for(int j = i+i; j<n; j+=i) {
                    vec[j] = false;
                }
            } 
        }
        return count;
    }
};

int main() {
    Solution solution;
    int n = 10;
    int result = solution.isPnum(n);
    cout << "Number of prime numbers: " << result << endl;
    return 0;
}