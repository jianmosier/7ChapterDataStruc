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

ListNode* reverse(ListNode* head) {
    ListNode* rightNode = nullptr;
    while(head) {
        ListNode* tempNode = head->next;
        head->next = rightNode;
        rightNode = head;
        head = tempNode;
    }
    return rightNode;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    ListNode dumpHead;
    ListNode* ptr = &dumpHead;

    for(auto num : nums){
        ptr->next = new ListNode(num);
        ptr = ptr->next;
    }

    ListNode* reverseList = reverse(dumpHead.next);

    while(reverseList) {
        cout<<reverseList->val<<' ';
        reverseList = reverseList->next;
    }

    return 0;
}