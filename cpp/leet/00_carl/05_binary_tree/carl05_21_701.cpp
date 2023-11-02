#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }

        TreeNode* tmp = root;
        TreeNode* last = nullptr;
        while (tmp) {
            last = tmp;
            if (tmp->val < val) {
                tmp = tmp->right;
            } else if (tmp->val > val) {
                tmp = tmp->left;
            }
        }

        if (last->val < val) {
            last->right = new TreeNode(val);
        }

        if (last->val > val) {
            last->left = new TreeNode(val);
        }

        return root;
    }
};

void test1() {
    TreeNode* two = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    TreeNode* root = new TreeNode(4, two, new TreeNode(7));

    Solution sn;
    int val = 5;
    TreeNode* newTree = sn.insertIntoBST(root, val);
    vector<int> nodes = tranverse_tree_by_level(newTree);
    print(nodes);

    std::cout << ", expected:[4,2,7,1,3,5]" << std::endl;
}

int main() {
    test1();
    return 0;
}