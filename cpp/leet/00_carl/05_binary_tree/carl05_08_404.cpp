#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root || (!root->left && !root->right)) {
            return 0;
        }
        postOrder(root);
        return sum;
    }

    void postOrder(TreeNode* node) {
        if (!node) {
            return;
        }

        if (node->left) {
            if (!node->left->left && !node->left->right) {
                sum += node->left->val;
            } else {
                postOrder(node->left);
            }
        }
        if (node->right) {
            postOrder(node->right);
        }
    }

private:
    int sum {0};
};

void test1() {
    TreeNode* twenty = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    TreeNode* root = new TreeNode(3, new TreeNode(9), twenty);

    Solution sn;
    int result = sn.sumOfLeftLeaves(root);
    std::cout << "result:" << result;
    std::cout << ", expected:24" << std::endl;
}

void test2() {
    TreeNode* root = new TreeNode(1);

    Solution sn;
    int result = sn.sumOfLeftLeaves(root);
    std::cout << "result:" << result;
    std::cout << ", expected:0" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}