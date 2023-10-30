#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return {};
        }

        vector<int> path;
        path.push_back(root->val);
        int sum = root->val;
        tranverse(root, path, sum, targetSum);

        return paths;
    }

    void tranverse(TreeNode* node, vector<int>& path, int sum, int targetSum) {
        if (!node->left && !node->right) {
            if (sum == targetSum) {
                paths.push_back(path);
            }
        }

        if (node->left) {
            path.push_back(node->left->val);
            tranverse(node->left, path, sum + node->left->val, targetSum);
            path.pop_back();
        }
        if (node->right) {
            path.push_back(node->right->val);
            tranverse(node->right, path, sum + node->right->val, targetSum);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> paths;
};

void test1() {
    TreeNode* eleven = new TreeNode(11, new TreeNode(7), new TreeNode(2));
    TreeNode* four = new TreeNode(4, eleven, nullptr);

    TreeNode* fourRight = new TreeNode(4, new TreeNode(5), new TreeNode(1));
    TreeNode* eight = new TreeNode(8, new TreeNode(13), fourRight);

    TreeNode* root = new TreeNode(5, four, eight);

    int target = 22;

    Solution sn;
    vector<vector<int>> result = sn.pathSum(root, target);
    print(result);
    std::cout << ", expected:[5,4,11,2],[5,8,4,5]" << std::endl;
}

void test2() {
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    int target = 5;

    Solution sn;
    vector<vector<int>> result = sn.pathSum(root, target);
    print(result);
    std::cout << ", expected:[]" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}