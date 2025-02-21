#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0),next(nullptr) {}
    ListNode(int x) : val(x),next(nullptr) {}
    ListNode(int x,ListNode *next) :val(x),next(next) {}
};

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *dummy = new ListNode(0);
            dummy->next = head;
            ListNode *p = dummy;
            ListNode *q = dummy;
            for(int i = 0; i<n;i++){
                q = q->next;
            }
            while(q->next != nullptr){
                p = p->next;
                q = q->next;
            }
            ListNode *NodeToDelete = p->next;
            p->next = p->next->next;
            delete NodeToDelete;
            return dummy->next;
        }
    };

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // 创建链表 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "initial: ";
    printList(head);

    Solution sol;
    ListNode* removeHead = sol.removeNthFromEnd(head,2);

    cout << "final: ";
    printList(removeHead);

    return 0;
}
