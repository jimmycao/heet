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
  
// double pointers
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* prev = head;
        ListNode* tmp = prev->next;
        ListNode* next = nullptr;
        while (tmp) {
            next = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = next;
        }
        head->next = nullptr;
        head = prev;
        return head;
    }
};

ListNode* createList(const std::vector<int>& nums) {
    ListNode* head = nullptr;
    ListNode* prev = nullptr;
    for (size_t i = 0; i < nums.size(); i++) {
        ListNode* tmp = new ListNode(nums[i]);
        if (i == 0) {
            head = tmp;
            prev = head;
            continue;
        }
        prev->next = tmp;
        prev = tmp;
    }
    return head;
}

void print(ListNode* head) {
    ListNode* tmp = head;
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