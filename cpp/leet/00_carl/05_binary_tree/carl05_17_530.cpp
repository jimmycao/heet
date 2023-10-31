#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        results.clear();
        int minDiff = INT_MAX;

        inOrder(root);

        for (int i = 1; i < results.size(); i++) {
            int diff = std::abs(results[i] - results[i-1]);
            minDiff = minDiff > diff ? diff : minDiff;
        }

        return minDiff;
    }

private:
    void inOrder(TreeNode* node) {
        if (!node) {
            return;
        }
        if (node->left) {
            inOrder(node->left);
        }

        results.push_back(node->val);

        if (node->right) {
            inOrder(node->right);
        }
    }

    vector<int> results;
};

void test1() {
    TreeNode* two = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    TreeNode* root = new TreeNode(4, two, new TreeNode(6));

    Solution sn;
    int result = sn.getMinimumDifference(root);
    std::cout << "result:" << result;
    std::cout << ", expected:1" << std::endl;
}

void test2() {
    TreeNode* fortyEight = new TreeNode(48, new TreeNode(12), new TreeNode(49));
    TreeNode* root = new TreeNode(1, new TreeNode(0), fortyEight);

    Solution sn;
    int result = sn.getMinimumDifference(root);
    std::cout << "result:" << result;
    std::cout << ", expected:1" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}