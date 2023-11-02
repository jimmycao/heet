#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};

class Solution3 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* tmp = root;
        while (tmp) {
            if (tmp->val > p->val && tmp->val > q->val) {
                tmp = tmp->left;
            } else if (tmp->val < p->val && tmp->val < q->val) {
                tmp = tmp->right;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};

class Solution2 {
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
    TreeNode* four = new TreeNode(4, new TreeNode(3), new TreeNode(5));
    TreeNode* two = new TreeNode(2, new TreeNode(0), four);

    TreeNode* eight = new TreeNode(8, new TreeNode(7), new TreeNode(9));

    TreeNode* root = new TreeNode(6, two, eight);

    Solution sn;
    TreeNode* result = sn.lowestCommonAncestor(root, two, eight);
    std::cout << "result:" << result->val;
    std::cout << ", expected:6" << std::endl;
}

int main() {
    test1();
    return 0;
}