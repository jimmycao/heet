#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val) {
            return root;
        }

        if (root->val < val) {
            return searchBST(root->right, val);
        }

        if (root->val > val) {
            return searchBST(root->left, val);
        }

        return nullptr;
    }
};

void test1() {
    TreeNode* two = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    TreeNode* root = new TreeNode(4, two, new TreeNode(7));

    int val = 2;

    Solution sn;
    TreeNode* sub = sn.searchBST(root, val);
    vector<int> results = tranverse_tree_by_level(sub);
    print(results);
    std::cout << ", expected:[2,1,3]" << std::endl;
}

int main() {
    test1();
    return 0;
}