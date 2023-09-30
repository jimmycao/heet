#include <vector>
#include <unordered_map>
#include <iostream>
#include <iterator>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode; 
        ListNode *tmp = head;

        int fromLast = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int a = 0;
            int b = 0;

            if (l1 != nullptr) {
                a = l1->val;
                l1 = l1->next;
            } 

            if (l2 != nullptr) {
                b = l2->val;
                l2 = l2->next;
            }

            int val = a + b + fromLast;
            if (val >= 10) {
                val -= 10;
                fromLast = 1;
            } else {
                fromLast = 0;
            }

            ListNode* node = new ListNode(val, nullptr);
            tmp->next = node;
            tmp = node;
        } // while end

        if (fromLast == 1) {
            ListNode *node = new ListNode(1, nullptr);
            tmp->next = node;
        }

        tmp =  head->next;
        delete head;
        return tmp;
    } 
};

ListNode* get_list(const std::vector<int>& data) {
    ListNode* curr = nullptr;

    for (int i = data.size()-1; i >= 0; i--) {
        // std::cout << i << "," << data[i] << std::endl;
        ListNode* node = new ListNode(data[i], curr);
        curr = node;
    }
    return curr;
}

void print(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void free_list(ListNode* head) {
    ListNode* tmp;
    while (head != nullptr) {
        tmp = head->next;
        delete head;
        head = tmp;
    }
}

int main() {
    // std::vector<int> data1 {2, 4, 3};
    // std::vector<int> data2 {5, 6, 4};

    // std::vector<int> data1 {0};
    // std::vector<int> data2 {0};

    std::vector<int> data1 {9, 9, 9, 9, 9, 9, 9};
    std::vector<int> data2 {9, 9, 9, 9};

    ListNode* l1 = get_list(data1);
    ListNode* l2 = get_list(data2);

    print(l1);
    print(l2);

    Solution s;
    ListNode* result = s.addTwoNumbers(l1, l2);

    print(result);

    free_list(l1);
    free_list(l2);
    free_list(result);

    return 0;
}