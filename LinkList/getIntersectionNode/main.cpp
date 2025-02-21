#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr) {}
};

class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            //同步开头
            ListNode *p = headA;
            ListNode *q = headB;
            int countA = 0;
            int countB = 0;
            while(p != nullptr){
                p = p->next;
                countA++;
            }
            while(q != nullptr){
                q = q->next;
                countB++;
            }

            p = headA;
            q = headB;

            while(countA != countB){
                if(countA > countB){
                    p = p->next;
                    countA--;
                }
                else if(countA < countB){
                    q = q->next;
                    countB--;
                }
            }

            //同时对比两节点
            while(p != nullptr && q != nullptr){
                if(p == q){
                    return q;
                }
                else{
                    p = p->next;
                    q = q->next;
                }
            }
            return nullptr;
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
    // 创建链表A: 4->1->8->4->5
    // 创建链表B: 5->0->1->8->4->5
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;
    printList(headA);
    printList(headB);

    Solution s;
    ListNode* res = s.getIntersectionNode(headA, headB);
    cout << "intersection node:" << res->val << endl;



    return 0;
}
