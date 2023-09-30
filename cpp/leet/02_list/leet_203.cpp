#include <climits>
#include <iostream>
#include <vector>
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return nullptr;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr) {
            if (curr->val != val) {
                prev = curr;
                curr = curr->next;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        }

        ListNode* newHead = head;
        if (head->val == val) {
            newHead = head->next;
            delete head;
            return newHead;
        }
        
        return head;
    }
};

ListNode* createList(const std::vector<int>& nums) {
    ListNode* head = nullptr;
    ListNode* curr = nullptr;
    for (int i = nums.size()-1; i >= 0; --i) {
        if (i == nums.size()-1) {
            curr = new ListNode(nums[i]);
            continue;
        } 

        head = new ListNode(nums[i], curr);
        curr = head;
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

ListNode* common(const std::vector<int>& nums, int val) {
    ListNode* newList = createList(nums);
    std::cout << "newList:" << std::endl;
    print(newList);

    Solution sn;
    return sn.removeElements(newList, val);
}

void test1() {
    std::vector<int> nums{1,2,6,3,4,5,6};
    int val = 6;
    ListNode* resultList = common(nums, val);
    std::cout << "resultList:" << std::endl;
    print(resultList);
}

void test2() {
    std::vector<int> nums{};
    int val = 1;
    ListNode* resultList = common(nums, val);
    std::cout << "resultList:" << std::endl;
    print(resultList);
}

void test3() {
    std::vector<int> nums{7,7,7,7};
    int val = 7;
    ListNode* resultList = common(nums, val);
    std::cout << "resultList:" << std::endl;
    print(resultList);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}