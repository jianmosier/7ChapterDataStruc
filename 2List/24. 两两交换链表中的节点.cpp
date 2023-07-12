#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int val): val(val), next(nullptr){}
    ListNode(int val, ListNode* next): val(val), next(next){}
};

class Solution {
public:
    
    ListNode* leftRight(ListNode* left, ListNode* lastRight){
        if(left == nullptr || left->next == nullptr) return left;
        ListNode* right;
        right = left->next;
        left->next = right->next;
        lastRight->next = right;
        right->next = left;
        return left;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode dumpHead;
        ListNode* ptrNode = &dumpHead;
        ptrNode->next = head;
        while(head != nullptr){
            ptrNode = leftRight(head,ptrNode);
            head = ptrNode->next;
        }
        return dumpHead.next;
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
    ListNode* outList = s.swapPairs(head);
    while(outList){
        cout<<outList->val<<" ";
        outList = outList->next;
    }
    return 0;
}

