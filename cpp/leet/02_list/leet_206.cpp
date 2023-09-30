#include <climits>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
  
//1. dummy-head list
//2. with stack
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        std::stack<ListNode*> stack;
        ListNode* curr;

        stack.push(nullptr);
        ListNode* tmp = head->next;
        while (tmp) {
            curr = tmp;
            tmp = tmp->next;
            stack.push(curr);
        }

        head->next = nullptr;
        ListNode* prev = head;
        curr = stack.top();
        while (curr) {
            curr->next = nullptr;
            prev->next = curr;
            prev = curr;
            stack.pop(); 
            curr = stack.top();   
        }

        return head;
    }
};

ListNode* createList(const std::vector<int>& nums) {
    ListNode* head = new ListNode;
    ListNode* prev = head;
    for (size_t i = 0; i < nums.size(); i++) {
        ListNode* tmp = new ListNode(nums[i]);
        prev->next = tmp;
        prev = tmp;
    }
    return head;
}

void print(ListNode* head) {
    ListNode* tmp = head->next;
    while (tmp) {
        std::cout << tmp->val << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

ListNode* common(const std::vector<int>& nums) {
    ListNode* head = createList(nums);
    std::cout << "orig:";
    print(head);

    Solution sn;
    return sn.reverseList(head);
}

void test1() {
    std::vector<int> nums{1,2,3,4,5};
    ListNode* resultList = common(nums);
    std::cout << "resultList:";
    print(resultList);
}

void test2() {
    std::vector<int> nums{1,2};
    ListNode* resultList = common(nums);
    std::cout << "resultList:";
    print(resultList);
}

void test3() {
    std::vector<int> nums{};
    ListNode* resultList = common(nums);
    std::cout << "resultList:";
    print(resultList);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}