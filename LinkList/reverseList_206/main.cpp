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
        ListNode* reverseList(ListNode* head) {
            ListNode* newHead = nullptr; // 新链表的头节点
            ListNode* next = nullptr; // 保存当前节点的下一个节点
            while (head != nullptr) {
                next = head->next; // 保存当前节点的下一个节点
                head->next = newHead; // 将当前节点插入到新链表的头部
                newHead = head; // 更新新链表的头节点
                head = next; // 移动到下一个节点
            }
            return newHead; // 返回新链表的头节点
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
    ListNode* reversedHead = sol.reverseList(head);

    cout << "final: ";
    printList(reversedHead);

    return 0;
}
