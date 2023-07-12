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
            head = head->next;
        }
        lessPtr->next = moreHead.next;
        morePtr->next = nullptr;
        return lessHead.next;
    }
};

int main(){
    Solution s;
    vector<int> inNode = {2,4,5,9,7,8,6};
    ListNode* head = new ListNode(inNode[0]);
    ListNode* ptr = head;
    for(int i = 1; i < inNode.size(); i++, ptr = ptr->next){
        ptr->next = new ListNode(inNode[i]);
    }
    ListNode* outList = s.partition(head, 5);
    while(outList){
        printf("%d ", outList->val);
        outList = outList->next;
    }
    return 0;
}


// int main(){
//     Solution s;
//     vector<int> nums = {1, 4, 3, 2, 5, 2};
//     ListNode* head = new ListNode(nums[0]);
//     ListNode* ptr = head;
//     for(int i = 1; i < nums.size(); i++){
//         ptr->next = new ListNode(nums[i]);
//         ptr = ptr->next;
//     }
//     ListNode* res = s.partition(head, 3);
//     while(res){
//         cout << res->val << " ";
//         res = res->next;
//     }
//     return 0;
// }