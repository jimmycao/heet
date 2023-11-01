#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (!root->left && !root->right) {
            return { root->val };
        }

        nums.clear();
        inOrder(root);

        for (auto item : nums) {
            num2cnt[item]++;
        }

        int maxCnt = INT_MIN;
        for (auto item : num2cnt) {
            if (item.second > maxCnt) {
                maxCnt = item.second;
            }
        }

        vector<int> results;
        for (auto item : num2cnt) {
            if (maxCnt == item.second) {
                results.push_back(item.first);
            }
        }

        return results;
    }

private:
    void inOrder(TreeNode* node) {
        if (!node) {
            return;
        }
        inOrder(node->left);
        nums.push_back(node->val);
        inOrder(node->right);
    }

    vector<int> nums;
    map<int, int> num2cnt;
};

void test1() {
    TreeNode* two = new TreeNode(2, new TreeNode(2), nullptr);
    TreeNode* root = new TreeNode(1, nullptr, two);

    Solution sn;
    vector<int> results = sn.findMode(root);
    print(results);
    std::cout << ", expected:[2]" << std::endl;
}

void test2() {
    TreeNode* root = new TreeNode(0);

    Solution sn;
    vector<int> results = sn.findMode(root);
    print(results);
    std::cout << ", expected:[0]" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}