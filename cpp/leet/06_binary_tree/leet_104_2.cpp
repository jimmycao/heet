#include "../../utils/tools.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return getHeight(root);
    }

    //postOrder
    int getHeight(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int leftH = getHeight(node->left);
        int rightH = getHeight(node->right);
        return 1 + std::max(leftH, rightH);
    }
};

void test1() {
    TreeNode* fifteenNode = new TreeNode(15);
    TreeNode* sevenNode = new TreeNode(7);
    TreeNode* twentyNode = new TreeNode(20, fifteenNode, sevenNode);

    TreeNode* nineNode = new TreeNode(9);

    TreeNode* root = new TreeNode(3, nineNode, twentyNode);

    Solution sn;
    int result = sn.maxDepth(root);
    std::cout << "result:" << result << ", expected:" << 3 << std::endl;
}

int main() {
    test1();
    return 0;
}