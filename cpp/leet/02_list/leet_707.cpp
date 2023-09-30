#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
  
class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* head_ {nullptr};
    int size_ {0};
public:
    MyLinkedList() {
        head_ = new ListNode;
    }
    
    int get(int index) {
        if (index > size_ - 1) {
            return -1;
        }
        ListNode* tmp = head_;
        for (int i = 0; i <= index; ++i) {
            tmp = tmp->next;
        }
        return tmp->val;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head_->next;
        head_->next = node;
        size_++;
    }
    
    void addAtTail(int val) {
        ListNode* tmp = head_;
        while (tmp->next) {
            tmp = tmp->next;
        }

        ListNode* node = new ListNode(val);

        tmp->next = node;
        size_++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size_) {
            return;
        }

        if (index == size_) {
            addAtTail(val);
            return;
        }

        ListNode* tmp = head_;
        ListNode* prev = head_;
        for (int i = 0; i <= index; ++i) {
            prev = tmp;
            tmp = tmp->next;
        }

        ListNode* node = new ListNode(val, tmp);
        prev->next = node;
        size_++;
    }
    
    void deleteAtIndex(int index) {
        if (index > size_-1) {
            return;
        }

        ListNode* tmp = head_;
        ListNode* prev = head_;
        for (int i = 0; i <= index; ++i) {
            prev = tmp;
            tmp = tmp->next;
        }

        prev->next = tmp->next;
        delete tmp;
        size_--;
    }

    void print() {
        std::cout << "size:" << size_ << ", ";

        ListNode* tmp = head_->next;
        while (tmp) {
            std::cout << tmp->val << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
};

void test1() {
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);
    myLinkedList.print();

    myLinkedList.addAtTail(3);
    myLinkedList.print();

    myLinkedList.addAtIndex(1, 2);   
    myLinkedList.print();

    std::cout << "expect: 2, get(1):" << myLinkedList.get(1) << std::endl;  

    myLinkedList.deleteAtIndex(1);
    myLinkedList.print();

    std::cout << "expect: 3, get(1):" << myLinkedList.get(1) << std::endl;   
}

void test2() {
    MyLinkedList myLinkedList;

    myLinkedList.addAtHead(7);
    myLinkedList.print();

    myLinkedList.addAtHead(2);
    myLinkedList.print();

    myLinkedList.addAtHead(1);
    myLinkedList.print();

    myLinkedList.addAtIndex(3, 0);   
    myLinkedList.print();

    myLinkedList.deleteAtIndex(2);
    myLinkedList.print();

    myLinkedList.addAtHead(6);
    myLinkedList.print();

    myLinkedList.addAtTail(4);
    myLinkedList.print();


    std::cout << "expect: 4, get(1):" << myLinkedList.get(4) << std::endl;  

    myLinkedList.addAtHead(4);
    myLinkedList.print();

    myLinkedList.addAtIndex(5, 0);   
    myLinkedList.print();

    myLinkedList.addAtHead(6);
    myLinkedList.print();
}

int main() {
    test1();
    // test2();
    return 0;
}