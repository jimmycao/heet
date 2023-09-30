//
// Created by c00770977 on 2023/5/2.
//
#include "../../utils/tools.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        return levelTraverseCheck(root);
    }

    bool levelTraverseCheck(TreeNode* root) {
        std::queue<TreeNode*> levelQueue;

        if (!root) {
            return true;
        }

        levelQueue.push(root);

        while (!levelQueue.empty()) {
            TreeNode* node = levelQueue.front();
            if (node->left) {
                levelQueue.push(node->left);
            }
            if (node->right) {
                levelQueue.push(node->right);
            }

            if (!isBalanceNode(node)) {
                return false;
            }
            levelQueue.pop();
        }

        return true;
    }

    bool isBalanceNode(TreeNode* node) {
        int leftH = 0;
        int rightH = 0;

        if (node->left) {
            leftH = getHeight(node->left);
        }

        if (node->right) {
            rightH = getHeight(node->right);
        }

        if (std::abs(leftH - rightH) <= 1) {
            return true;
        } else {
            return false;
        }
    }

    int getHeight(TreeNode* node) {
        if (!node) {
            return 0;
        }

        // when to get height, we use postOrder tranverse
        int leftH = getHeight(node->left);
        int rightH = getHeight(node->right);
        return 1 + std::max(leftH, rightH);
    }
};

void test1() {
    TreeNode* fifteenNode = new TreeNode(15);
    TreeNode* sevenNode = new TreeNode(7);
    TreeNode* twentyNode = new TreeNode(20, sevenNode, fifteenNode);

    TreeNode* nineNode = new TreeNode(9);

    TreeNode* root = new TreeNode(3, nineNode, twentyNode);

    Solution sn;
    bool result = sn.isBalanced(root);
    std::cout << std::boolalpha;
    std::cout << "result:" << result << ", expected:" << true << std::endl;
}

void test2() {
    TreeNode* fourLeftNode = new TreeNode(4);
    TreeNode* fourRightNode = new TreeNode(4);
    TreeNode* threeLeftNode = new TreeNode(3, fourLeftNode, fourRightNode);
    TreeNode* threeRightNode = new TreeNode(3);
    TreeNode* twoLeftNode = new TreeNode(2, threeLeftNode, threeRightNode);
    TreeNode* twoRightNode = new TreeNode(2);
    TreeNode* root = new TreeNode(1, twoLeftNode, twoRightNode);

    Solution sn;
    bool result = sn.isBalanced(root);
    std::cout << std::boolalpha;
    std::cout << "result:" << result << ", expected:" << false << std::endl;
}

void test3() {
    TreeNode* root = nullptr;

    Solution sn;
    bool result = sn.isBalanced(root);
    std::cout << std::boolalpha;
    std::cout << "result:" << result << ", expected:" << true << std::endl;
}

void test4() {
    TreeNode* twoNode = new TreeNode(2);
    TreeNode* root = new TreeNode(1, twoNode, nullptr);

    Solution sn;
    bool result = sn.isBalanced(root);
    std::cout << std::boolalpha;
    std::cout << "result:" << result << ", expected:" << true << std::endl;
}

void test5() {
    TreeNode* fourLeftNode = new TreeNode(4);
    TreeNode* threeLeftNode = new TreeNode(3, fourLeftNode, nullptr);

    TreeNode* fourRightNode = new TreeNode(4);
    TreeNode* threeRightNode = new TreeNode(3, nullptr, fourRightNode);

    TreeNode* twoLeftNode = new TreeNode(2, threeLeftNode, nullptr);
    TreeNode* twoRightNode = new TreeNode(2, nullptr, threeRightNode);

    TreeNode* root = new TreeNode(1, twoLeftNode, twoRightNode);

    Solution sn;
    bool result = sn.isBalanced(root);
    std::cout << std::boolalpha;
    std::cout << "result:" << result << ", expected:" << false << std::endl;
}

void test6() {
    TreeNode* fifteenNode = new TreeNode(15);
    TreeNode* sevenNode = new TreeNode(7);

    TreeNode* twentyNode = new TreeNode(20, fifteenNode, sevenNode);

    TreeNode* nineNode = new TreeNode(9);
    TreeNode* root = new TreeNode(3, nineNode, twentyNode);

    Solution sn;
    bool result = sn.isBalanced(root);
    std::cout << std::boolalpha;
    std::cout << "result:" << result << ", expected:" << true << std::endl;
}

int main() {
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
    test6();
    return 0;
}