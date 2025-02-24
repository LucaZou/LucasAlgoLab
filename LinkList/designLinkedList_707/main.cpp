#include <iostream>
#include <vector>

using namespace std;

class MyLinkedList {
public:
    struct LinkNode {
        int val;
        LinkNode *next;
        LinkNode(int x) : val(x), next(NULL) {}
    };
    MyLinkedList() {
        _dummyHead = new LinkNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index > (_size - 1)){
            return -1;
        }
        LinkNode* p = _dummyHead->next;
        for(int i = 0; i < index; i++){
            p = p->next;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        LinkNode* newNode = new LinkNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkNode* newNode = new LinkNode(val);
        LinkNode* p =_dummyHead;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = newNode;
        _size++;
        
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size){
            return;
        }
        LinkNode* newNode = new LinkNode(val);
        LinkNode* p = _dummyHead;
        for(int i=0;i<index;i++){
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= _size || index < 0){
            return;
        }
        LinkNode* p = _dummyHead;
        for(int i=0;i<index;i++){
            p = p->next;
        }
        LinkNode* nodeToDelete = p->next;
        p->next = nodeToDelete->next;
        delete nodeToDelete;
        _size--;
    }

private:
    int _size;
    LinkNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtTail(1);
    obj->addAtTail(2);
    // print
    cout << obj->get(0) << "\n";
    cout <<obj->get(1) << "\n";
    obj->addAtIndex(1,3);
    cout << "-------------------\n";
    cout << obj->get(0) << "\n";
    cout << obj->get(1) << "\n";
    cout << obj->get(2) << "\n";
    obj->deleteAtIndex(1);
    cout << obj->get(0) << "\n";
    cout << obj->get(1) << "\n";
    cout << obj->get(2) << "\n";
    return 0;
}