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
  
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* tmp = head;
        while (tmp) {
            size++;
            tmp = tmp->next;
        }

        if (size == 1 && n == 1) {
            delete head;
            return nullptr;
        }

        int idx = size - n;

        if (idx != 0) {
             ListNode* prev = head;
            for (int i = 0; i < idx-1; ++i) {
                prev = prev->next;
            }

            tmp = prev->next;

            prev->next = tmp->next;
            delete tmp;
        } else {
            tmp = head;
            head = head->next;
            delete tmp;
        }

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

ListNode* common(const std::vector<int>& nums,  int n) {
    ListNode* head = createList(nums);
    std::cout << "orig:";
    print(head);

    Solution sn;
    return sn.removeNthFromEnd(head, n);
}

void test1() {
    std::vector<int> nums{1,2,3,4,5};
    int n = 2;
    ListNode* resultList = common(nums, n);
    std::cout << "resultList:";
    print(resultList);
    std::cout << "expected:" << "1,2,3,5" << std::endl;
}

void test2() {
    std::vector<int> nums{1};
    int n = 1;
    ListNode* resultList = common(nums, n);
    std::cout << "resultList:";
    print(resultList);
    std::cout << "expected:" << "" << std::endl;
}

void test3() {
    std::vector<int> nums{1, 2};
    int n = 1;
    ListNode* resultList = common(nums, n);
    std::cout << "resultList:";
    print(resultList);
    std::cout << "expected:" << "1" << std::endl;
}

void test4() {
    std::vector<int> nums{1, 2};
    int n = 2;
    ListNode* resultList = common(nums, n);
    std::cout << "resultList:";
    print(resultList);
    std::cout << "expected:" << "2" << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}