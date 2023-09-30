//
// Created by c00770977 on 2023/5/2.
//
#include "../../utils/tools.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int total = 0;
        if (!root) {
            return 0;
        }

        if (root->left) {
            tranverse(root->left, true, total);
        }
        if (root->right) {
            tranverse(root->right, false, total);
        }
        return total;
    }

    void tranverse(TreeNode* node, bool left, int& total) {
        if (!node->left && !node->right && left) {
            total += node->val;
        }

        if (node->left) {
            tranverse(node->left, true, total);
        }

        if (node->right) {
            tranverse(node->right, false, total);
        }
    }
};

void test1() {
    TreeNode* fifteenNode = new TreeNode(15);
    TreeNode* sevenNode = new TreeNode(7);
    TreeNode* twentyNode = new TreeNode(20, fifteenNode, sevenNode);

    TreeNode* nineNode = new TreeNode(9);
    TreeNode* root = new TreeNode(3, nineNode, twentyNode);

    Solution sn;
    int result = sn.sumOfLeftLeaves(root);
    std::cout << "result:" << result << ", expected:" << 24 << std::endl;
}

void test2() {
    TreeNode* root = new TreeNode(1);

    Solution sn;
    int result = sn.sumOfLeftLeaves(root);
    std::cout << "result:" << result << ", expected:" << 0 << std::endl;

}

int main() {
    test1();
    test2();
    return 0;
}