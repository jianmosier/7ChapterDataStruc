//力扣21题，合并两个有序链表
// Created by admin on 2021/3/7.
//
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int val):val(val),next(nullptr){}
    ListNode(int val,ListNode* next):val(val),next(next){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dumpHead = new ListNode();
        ListNode* ptr = dumpHead;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                ptr->next = l1;
                l1 = l1->next;
                ptr = ptr->next;
            }else{
                ptr->next = l2;
                l2 = l2->next;
                ptr = ptr->next;
            }
        }
        if(l1 != nullptr){
            ptr->next = l1;
        }
        if(l2 != nullptr){
            ptr->next = l2;
        }
        return dumpHead->next;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2,4};
    vector<int> nums2 = {1,3,4};
    ListNode* head1 = new ListNode(nums1[0]);
    ListNode* head2 = new ListNode(nums2[0]);
    ListNode* ptr1 = head1;
    ListNode* ptr2 = head2;
    for(int i=1; i<nums1.size(); i++){
        ptr1->next = new ListNode(nums1[i]);
        ptr1 = ptr1->next;
    }
    for(int i=1; i<nums2.size(); i++){
        ptr2->next = new ListNode(nums2[i]);
        ptr2 = ptr2->next;
    }
    ListNode* outList = s.mergeTwoLists(head1,head2);
    while(outList){
        cout<<outList->val<<" ";
        outList = outList->next;
    }
    return 0;
}


