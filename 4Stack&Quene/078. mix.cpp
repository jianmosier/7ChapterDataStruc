#include<iostream>
#include<vector>
#include<climits>

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
        ListNode dumpHead(0); // Initialize with value 0 for clarity
        ListNode* ptr = &dumpHead;

        while (true) {
            int smallestFlag = -1; 
            int smallestVal = INT_MAX;  // Initialize with the largest possible integer value

            for (int i = 0; i < lists.size(); i++) {
                if (!lists[i]) continue;
                if (lists[i]->val < smallestVal) {
                    smallestVal = lists[i]->val;
                    smallestFlag = i;
                }
            }

            if (smallestFlag == -1) break;  // All lists are empty or have been processed

            ptr->next = lists[smallestFlag];
            lists[smallestFlag] = lists[smallestFlag]->next;
            ptr = ptr->next;

            // Remove empty lists
            if (!lists[smallestFlag]) {
                lists.erase(lists.begin() + smallestFlag);
            }
        }
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

