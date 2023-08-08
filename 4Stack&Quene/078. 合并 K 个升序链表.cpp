#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int value) : val(value), next(nullptr) {}
    ListNode(int value, ListNode* nextPtr) : val(value), next(nextPtr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dumpHead;
        ListNode* ptr = &dumpHead;

        int smallestFlag = 0;
        int smallestVal = 0;
        while(!lists.empty()) {
            for(int i = 0; i < lists.size(); i++) {
                if(!lists[i]) continue;
                if(lists[i]->val < smallestVal) {
                    smallestVal = lists[i]->val;
                    smallestFlag = i;
                }
                if(i == lists.size() - 1) {
                    ptr->next = lists[smallestFlag];
                    lists[smallestFlag] = lists[smallestFlag]->next;
                    ptr = ptr->next;
                }
            }
        }
        return dumpHead.next;
    }
    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        ListNode dumpHead;
        ListNode* ptr = &dumpHead;
        while(list1 && list2) {
            if(list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            }
            else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        ptr->next = list1 ? list1 : list2;
        return dumpHead.next;
    }
};


bool compareLinkedList(ListNode* a, ListNode* b) {
    while (a && b) {
        if (a->val != b->val) return false;
        a = a->next;
        b = b->next;
    }
    return !a && !b;  // both should be nullptr to be equal
}

void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr\n";
}

void test() {
    Solution s;

    // Test case 1
    ListNode* a1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* b1 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* c1 = new ListNode(2, new ListNode(6));
    vector<ListNode*> lists1 = {a1, b1, c1};
    ListNode* result1 = s.mergeKLists(lists1);
    ListNode* expected1 = new ListNode(1, new ListNode(1, new ListNode(2, 
        new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(5, 
        new ListNode(6))))))));
    if (compareLinkedList(result1, expected1)) {
        cout << "Test case 1 passed!\n";
    } else {
        cout << "Test case 1 failed.\n";
        cout << "Expected: ";
        printLinkedList(expected1);
        cout << "Got: ";
        printLinkedList(result1);
    }

    // Add more test cases as needed...
}

int main() {
    test();
    return 0;
}
