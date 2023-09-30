#include "../../utils/tools.h"

class Solution {
public:
    int countNodes(TreeNode* root) {
        int num = 0;
        count(root, num);
        return num;
    }

    void count(TreeNode* node, int& num) {
        if (!node) {
            return;
        }

        if (node) {
            num++;
        }

        if (node->left) {
            count(node->left, num);
        }

        if (node->right) {
            count(node->right, num);
        }
    }
};

void test1() {
    TreeNode* fourNode = new TreeNode(4);
    TreeNode* fiveNode = new TreeNode(5);
    TreeNode* twoNode = new TreeNode(2, fourNode, fiveNode);

    TreeNode* sixNode = new TreeNode(6);
    TreeNode* threeNode = new TreeNode(3, sixNode, nullptr);

    TreeNode* root = new TreeNode(1, twoNode, threeNode);

    Solution sn;
    int result = sn.countNodes(root);
    std::cout << "result:" << result << ", expected:" << 6 << std::endl;
}

void test2() {
    TreeNode* root = nullptr;

    Solution sn;
    int result = sn.countNodes(root);
    std::cout << "result:" << result << ", expected:" << 0 << std::endl;
}

void test3() {
    TreeNode* root = new TreeNode(1);

    Solution sn;
    int result = sn.countNodes(root);
    std::cout << "result:" << result << ", expected:" << 1 << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}