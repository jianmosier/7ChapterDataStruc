#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int val): val(val), next(nullptr){}
    ListNode(int val,ListNode* next): val(val), next(next){}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* rightNode = nullptr;
        while(head){
            ListNode* tempNode = head->next;
            head->next = rightNode;
            rightNode = head;
            head = tempNode;
        }
        return rightNode;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rl1 = reverseList(l1);
        ListNode* rl2 = reverseList(l2);
        ListNode dumpHead;
        ListNode* ptr = &dumpHead;
        int sum = 0;
        while(rl1 && rl2) {
            sum += rl1->val + rl2->val;
            ptr->next = new ListNode(sum % 10);
            rl1 = rl1->next;
            rl2 = rl2->next;
            ptr = ptr->next;
            sum /= 10;
        }
        while(rl1){
            sum += rl1->val;
            ptr->next = new ListNode(sum % 10);
            rl1 = rl1->next;
            ptr = ptr->next;
            sum /= 10;
        }
        while(rl2){
            sum += rl2->val;
            ptr->next = new ListNode(sum % 10);
            rl2 = rl2->next;
            ptr = ptr->next;
            sum /= 10;
        }
        ptr->next = sum ? new ListNode(sum) : nullptr;
        return reverseList(dumpHead.next);
    }
};

int main(){
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {1,2,3,4,5,7,8,9};
    ListNode dumpHead1, dumpHead2;
    ListNode* ptr1 = &dumpHead1;
    ListNode* ptr2 = &dumpHead2;

    for(auto num1 : nums1){
        ptr1->next = new ListNode(num1);
        ptr1 = ptr1->next;
    }

    for(auto num2 : nums2){
        ptr2->next = new ListNode(num2);
        ptr2 = ptr2->next;
    }

    Solution s;

    ListNode* sumList = s.addTwoNumbers(dumpHead1.next, dumpHead2.next);

    while(sumList) {
        cout<<sumList->val<<' ';
        sumList = sumList->next;
    }

    return 0;
}