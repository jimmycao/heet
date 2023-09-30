#include "../../utils/tools.h"

class Solution {
public:
    int minDepth(TreeNode* root) {
        return getMinDepth(root);
    }

    int getMinDepth(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int leftH = getMinDepth(node->left);
        int rightH = getMinDepth(node->right);
        if (leftH == 0 && rightH != 0) {
            return 1 + rightH;
        }

        if (leftH != 0 && rightH == 0) {
            return 1 + leftH;
        }

        return 1 + std::min(leftH, rightH);
    }
};

void test1() {
    TreeNode* fifteenNode = new TreeNode(15);
    TreeNode* sevenNode = new TreeNode(7);
    TreeNode* twentyNode = new TreeNode(20, fifteenNode, sevenNode);

    TreeNode* nineNode = new TreeNode(9);

    TreeNode* root = new TreeNode(3, nineNode, twentyNode);

    Solution sn;
    int result = sn.minDepth(root);
    std::cout << "result:" << result << ", expected:" << 2 << std::endl;
}

void test2() {
    TreeNode* sixNode = new TreeNode(6);
    TreeNode* fiveNode = new TreeNode(5, nullptr, sixNode);

    TreeNode* fourNode = new TreeNode(4, nullptr, fiveNode);
    TreeNode* threeNode = new TreeNode(3, nullptr, fourNode);
    TreeNode* root = new TreeNode(2, nullptr, threeNode);

    Solution sn;
    int result = sn.minDepth(root);
    std::cout << "result:" << result << ", expected:" << 5 << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}