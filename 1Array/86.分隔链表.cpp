#include<iostream>
#include<stdio.h>

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
        ListNode* varNode, *constNode, *largeNode, *largeHead, *conectNode;
        varNode->next = head;
        constNode = varNode;
        while(varNode->next != nullptr && varNode->val < x){
            varNode = varNode->next;     
        }
        if(varNode->val >=  x){
            conectNode = varNode;
            largeNode->next = varNode;
            largeHead = largeNode;
            while(varNode->next != nullptr){
                if( varNode->val < x){
                    varNode = varNode->next;    
                }
                else{
                    largeNode->next = varNode;
                }
            }
        }
        else{
            return constNode->next;
        }
        conectNode->next = largeHead->next;
        return constNode->next;
    }
};

int main(){
}