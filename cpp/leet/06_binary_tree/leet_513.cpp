//
// Created by c00770977 on 2023/5/2.
//
#include "../../utils/tools.h"

class Solution {
private:
    int depth_ {-1};
    int result_ {INT_MIN};
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root) {
            return 0;
        }

        result_ = root->val;

        int depth = 1;

        if (root->left) {
            tranverse(root->left, true, depth);
        }

        if (root->right) {
            tranverse(root->right, false, depth);
        }

        return result_;
    }

    void tranverse(TreeNode* node, bool isLeft, int& depth) {
        if (!node->left && !node->right && isLeft) {
            depth++;
            if (depth > depth_) {
                result_ = node->val;
            }
        }

        if (node->left) {
            tranverse(node->left, true, depth);
        }

        if (node->right) {
            tranverse(node->right, false, depth);
        }
    }
};

void test1() {
    TreeNode* oneNode = new TreeNode(1);
    TreeNode* threeNode = new TreeNode(3);
    TreeNode* root = new TreeNode(2, oneNode, threeNode);

    Solution sn;
    int result = sn.findBottomLeftValue(root);
    std::cout << "result:" << result << ", expected:" << 1 << std::endl;
}

void test2() {
    TreeNode* fourNode = new TreeNode(4);
    TreeNode* twoNode = new TreeNode(2,fourNode, nullptr);

    TreeNode* sevenNode = new TreeNode(7);
    TreeNode* fiveNode = new TreeNode(5, sevenNode, nullptr);

    TreeNode* sixNode = new TreeNode(6);

    TreeNode* threeNode = new TreeNode(3, fiveNode, sixNode);

    TreeNode* root = new TreeNode(1, twoNode, threeNode);

    Solution sn;
    int result = sn.findBottomLeftValue(root);
    std::cout << "result:" << result << ", expected:" << 7 << std::endl;
}

void test3() {
    TreeNode* minusOneNode = new TreeNode(-1);
    TreeNode* root = new TreeNode(0, minusOneNode, nullptr);

    Solution sn;
    int result = sn.findBottomLeftValue(root);
    std::cout << "result:" << result << ", expected:" << -1 << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}