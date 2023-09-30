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
    ListNode* detectCycle(ListNode* head) {
        std::vector<ListNode*> nodes;

        ListNode* curr = head;
        ListNode* entrance = nullptr;
        while (curr) {
            auto it = std::find(nodes.begin(), nodes.end(), curr);
            if (it != nodes.end()) {
                entrance = curr;
                break;
            } else {
                nodes.push_back(curr);
                curr = curr->next;
            }
        }

        return entrance;
    }
};

ListNode* createList(const std::vector<int>& nums, int pos) {
    ListNode* head = nullptr;
    ListNode* prev = nullptr;

    ListNode* entrance = nullptr;
    ListNode* tmp = nullptr;
    for (size_t i = 0; i < nums.size(); i++) {
        tmp = new ListNode(nums[i]);
        if (i == 0) {
            head = tmp;
            prev = head;

            if (i == pos) {
                entrance = tmp;
            }
            continue;
        }
        prev->next = tmp;
        prev = tmp;

        if (i == pos) {
            entrance = tmp;
        }
    }

    tmp->next = entrance;

    return head;
}

void print(ListNode* head) {
    std::vector<ListNode*> nodes;

    ListNode* tmp = head;
    while (tmp) {
        auto it = std::find(nodes.begin(), nodes.end(), tmp);
        if (it != nodes.end()) {
            break;
        } else {
            std::cout << tmp->val << " ";
            nodes.push_back(tmp);
            tmp = tmp->next;
        }
    }
    std::cout << std::endl;
}

ListNode* common(const std::vector<int>& nums,  int pos) {
    ListNode* head = createList(nums, pos);
    std::cout << "orig:";
    print(head);

    Solution sn;
    return sn.detectCycle(head);
}

void test1() {
    std::vector<int> nums{3,2,0,-4};
    int n = 1;
    ListNode* resultList = common(nums, n);
    std::cout << "resultList:";
    print(resultList);
    std::cout << "expected:" << "2, 0, 4" << std::endl;
}

void test2() {
    std::vector<int> nums{1,2};
    int n = 0;
    ListNode* resultList = common(nums, n);
    std::cout << "resultList:";
    print(resultList);
    std::cout << "expected:" << "1,2" << std::endl;
}

void test3() {
    std::vector<int> nums{1};
    int n = -1;
    ListNode* resultList = common(nums, n);
    std::cout << "resultList:";
    print(resultList);
    std::cout << "expected:" << "" << std::endl;
}

int main() {
    // test1();
    // test2();
    test3();
    return 0;
}