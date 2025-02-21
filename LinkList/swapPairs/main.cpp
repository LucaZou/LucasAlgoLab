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
        ListNode* swapPairs(ListNode* head) {
            ListNode* dummy = new ListNode(0); // 创建一个虚拟头节点
            dummy->next = head;
            ListNode* p = dummy;
            while (p->next != nullptr && p->next->next != nullptr){
                ListNode *tmp1 = p->next;
                ListNode *tmp2 = p->next->next->next;
                
                p->next = p->next->next;
                p->next->next = tmp1;
                p->next->next->next = tmp2;

                p = p->next->next;
            }
            ListNode* result = dummy->next;
            delete dummy; // 释放虚拟头节点
            return result;
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

    cout << "initial: ";
    printList(head);

    Solution sol;
    ListNode* swap = sol.swapPairs(head);

    cout << "final: ";
    printList(swap);

    return 0;

}