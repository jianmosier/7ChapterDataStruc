#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessHead, moreHead;
        ListNode *lessPtr, *morePtr;
        lessPtr = &lessHead;
        morePtr = &moreHead;
        while(head){
            if(head->val < x){
                lessPtr->next = head;
                lessPtr = head;
            }
            else{
                morePtr->next = head;
                morePtr = head;
            }
            head->next = head;
        }
        lessPtr->next = moreHead.next;
        return lessHead.next;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 4, 3, 2, 5, 2};
    ListNode* head = new ListNode(nums[0]);
    ListNode* ptr = head;
    for(int i = 1; i < nums.size(); i++){
        ptr->next = new ListNode(nums[i]);
        ptr = ptr->next;
    }
    ListNode* res = s.partition(head, 3);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}