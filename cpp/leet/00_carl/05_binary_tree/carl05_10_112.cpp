#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        int sum = root->val;
        preOrder(root, sum, targetSum);
        return result;
    }

    void preOrder(TreeNode* node, int sum, int target) {
        if (node && !node->left && !node->right) {
            if (sum == target) {
                result = true;
            }
        }

        if (node->left) {
            preOrder(node->left, sum + node->left->val, target);
        }
        if (node->right) {
            preOrder(node->right, sum + node->right->val, target);
        }
    }
private:
    bool result {false};
};

void test1() {
    TreeNode* eleven = new TreeNode(11, new TreeNode(7), new TreeNode(2));
    TreeNode* four = new TreeNode(4, eleven, nullptr);

    TreeNode* fourRight = new TreeNode(4, nullptr, new TreeNode(1));
    TreeNode* eight = new TreeNode(8, new TreeNode(13), fourRight);

    TreeNode* root = new TreeNode(5, four, eight);

    int target = 22;

    Solution sn;
    bool result = sn.hasPathSum(root, target);
    std::cout << std::boolalpha;
    std::cout << "result:" << result;
    std::cout << ", expected:true" << std::endl;
}

void test2() {
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    int target = 5;

    Solution sn;
    bool result = sn.hasPathSum(root, target);
    std::cout << std::boolalpha;
    std::cout << "result:" << result;
    std::cout << ", expected:false" << std::endl;
}

void test3() {
    TreeNode* root = nullptr;

    int target = 0;

    Solution sn;
    bool result = sn.hasPathSum(root, target);
    std::cout << std::boolalpha;
    std::cout << "result:" << result;
    std::cout << ", expected:false" << std::endl;
}


int main() {
    test1();
    test2();
    test3();
    return 0;
}