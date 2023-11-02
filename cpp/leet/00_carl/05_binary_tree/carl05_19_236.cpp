#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == nullptr) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) {
            return root;
        }

        if (left && !right) {
            return left;
        } else if (!left && right) {
            return right;
        } else {
            return nullptr;
        }
    }
};

void test1() {
    TreeNode* two = new TreeNode(2, new TreeNode(7), new TreeNode(4));
    TreeNode* five = new TreeNode(5, new TreeNode(6), two);

    TreeNode* one = new TreeNode(1, new TreeNode(1), new TreeNode(8));

    TreeNode* root = new TreeNode(3, five, one);

    Solution sn;
    TreeNode* result = sn.lowestCommonAncestor(root, five, one);
    std::cout << "result:" << result->val;
    std::cout << ", expected:3" << std::endl;
}

int main() {
    test1();
//    test2();
    return 0;
}