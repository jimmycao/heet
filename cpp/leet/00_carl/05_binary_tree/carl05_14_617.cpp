#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) {
            return root2;
        }
        if (!root2) {
            return root1;
        }

        TreeNode* root = new TreeNode(0);
        root->val = root1->val + root2->val;

        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }
};

void test1() {
    TreeNode* three1 = new TreeNode(3, new TreeNode(5), nullptr);
    TreeNode* root1 = new TreeNode(1, three1, new TreeNode(2));

    TreeNode* one2 = new TreeNode(1, nullptr, new TreeNode(4));
    TreeNode* three2 = new TreeNode(3, nullptr, new TreeNode(7));
    TreeNode* root2 = new TreeNode(2, one2, three2);


    Solution sn;
    TreeNode* root = sn.mergeTrees(root1, root2);
    vector<int> results = tranverse_tree_by_level(root);
    print(results);
    std::cout << ", expected:[3,4,5,5,4,null,7]" << std::endl;
}

int main() {
    test1();
//    test2();
    return 0;
}