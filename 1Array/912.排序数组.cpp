#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

class Solutions{
public:
    void leftRight(vector<int>& array, int m , int n){
        if (n - m <= 1) return;
        int i = m, j = n;
        int pivot = array[m + rand()%(n - m + 1)];
        while(i<j){
            while(array[i] < pivot) i++;
            while(array[j] > pivot) j--;
            if(i<j){
                swap(array[i],array[j]);
                i++;
                j--;
            }
        }
        leftRight(array,m,j);
        leftRight(array,i,n);
    }

    vector<int> order(vector<int>& nums){
        leftRight(nums, 0, nums.size()-1);
        return nums;
    }
};



int main(){
    Solutions s;
    vector<int> inNums = {2,0,3,0,5,5,7,9,8};
    vector<int> outNums = s.order(inNums);
    for(int i = 0; i < outNums.size(); i++){
        printf("%d ", outNums[i]);
    }
}