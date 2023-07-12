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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dumpHead;
        ListNode* dumpPtr = &dumpHead;

        while(list1 != nullptr && list2 != nullptr){
            if (list1->val < list2->val) {
                dumpPtr->next = list1;
                list1 = list1->next;
            } else {
                dumpPtr->next = list2;
                list2 = list2->next;
            }
            dumpPtr = dumpPtr->next;
        }
        dumpPtr->next = (list1 == nullptr) ? list2 : list1;
        return dumpHead.next;
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


