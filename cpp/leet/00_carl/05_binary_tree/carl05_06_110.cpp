#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        getHeight(root);
        return isBalance;
    }

    int getHeight(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int left = getHeight(node->left);
        int right = getHeight(node->right);

        if (abs(left-right) > 1) {
            isBalance = false;
        }

        return 1 + std::max(left, right);
    }

private:
    bool isBalance {true};
};

void test1() {
    TreeNode* twenty = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    TreeNode* root = new TreeNode(3, new TreeNode(9), twenty);

    Solution sn;
    bool result = sn.isBalanced(root);
    std::cout << std::boolalpha;
    std::cout << "result:" << result << std::endl;
    std::cout << ", expected:true" << std::endl;
}

void test2() {
    TreeNode* three = new TreeNode(3, new TreeNode(4), new TreeNode(4));
    TreeNode* two = new TreeNode(2, three, new TreeNode(3));
    TreeNode* root = new TreeNode(1, two, new TreeNode(2));

    Solution sn;
    bool result = sn.isBalanced(root);
    std::cout << std::boolalpha;
    std::cout << "result:" << result << std::endl;
    std::cout << ", expected:false" << std::endl;
}

void test3() {
    TreeNode* root = nullptr;

    Solution sn;
    bool result = sn.isBalanced(root);
    std::cout << std::boolalpha;
    std::cout << "result:" << result << std::endl;
    std::cout << ", expected:true" << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}