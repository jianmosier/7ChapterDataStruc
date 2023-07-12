#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* halfNode = head;
        int len = 1;
        while(head->next != nullptr){
            len++;
            head = head->next;
        }
        int j = len/2;
        while(j>0){
            halfNode =  halfNode->next;
            j--;
        }
        return halfNode;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,5};
    ListNode* head = new ListNode(nums[0]);
    ListNode* ptr = head;
    for(int i=1; i<nums.size(); i++){
        ptr->next = new ListNode(nums[i]);
        ptr = ptr->next;
    }
    ListNode* outList = s.middleNode(head);
    while(outList){
        cout<<outList->val<<" ";
        outList = outList->next;
    }
    return 0;
}