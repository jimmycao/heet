#include "../../utils/tools.h"

class Solution {
public:
    void inOrder(TreeNode* root, std::vector<int>& result) {
        if (root->left) {
            inOrder(root->left, result);
        }
        if (root) {
            result.push_back(root->val);
        }
        if (root->right) {
            inOrder(root->right, result);
        }
    }

    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (root) {
            inOrder(root, result);
        }
        return result;
    }
};

void test1() {
    TreeNode* threeNode = new TreeNode(3);
    TreeNode* twoNode = new TreeNode(2, threeNode, nullptr);
    TreeNode* root = new TreeNode(1, nullptr, twoNode);


    Solution sn;
    std::vector<int> result = sn.inorderTraversal(root);

    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << "1,3,2" << std::endl;
}

void test2() {
    TreeNode* root = nullptr;

    Solution sn;
    std::vector<int> result = sn.inorderTraversal(root);

    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << " " << std::endl;
}

void test3() {
    TreeNode* root = new TreeNode(1);

    Solution sn;
    std::vector<int> result = sn.inorderTraversal(root);

    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << 1 << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}