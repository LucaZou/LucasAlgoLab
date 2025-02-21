#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr) {}
};

class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode *slow = head;
            ListNode *fast = head;
            while(fast!= nullptr && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;

                if(slow == fast){
                    ListNode *index1 = fast;
                    ListNode *index2 = head;
                    while(index1 != index2){
                        index1 = index1->next;
                        index2 = index2->next;
                    }
                    return index1;
                }
            }
            return nullptr;
        }
    };

int main(){
    ListNode *head = new ListNode(3);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(0);
    ListNode *node3 = new ListNode(-4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;
    Solution s;
    ListNode *res = s.detectCycle(head);
    cout<<res->val<<endl;
    return 0;
}