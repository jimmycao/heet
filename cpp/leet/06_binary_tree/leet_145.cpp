#include "../../utils/tools.h"

class Solution {
public:
    void postOrder(TreeNode* root, std::vector<int>& result) {
        if (root->left) {
            postOrder(root->left, result);
        }
        if (root->right) {
            postOrder(root->right, result);
        }
        if (root) {
            result.push_back(root->val);
        }
    }

    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (root) {
            postOrder(root, result);
        }
        return result;
    }
};

void test1() {
    TreeNode* threeNode = new TreeNode(3);
    TreeNode* twoNode = new TreeNode(2, threeNode, nullptr);
    TreeNode* root = new TreeNode(1, nullptr, twoNode);


    Solution sn;
    std::vector<int> result = sn.postorderTraversal(root);

    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << "3,2,1" << std::endl;
}

void test2() {
    TreeNode* root = nullptr;

    Solution sn;
    std::vector<int> result = sn.postorderTraversal(root);

    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << " " << std::endl;
}

void test3() {
    TreeNode* root = new TreeNode(1);

    Solution sn;
    std::vector<int> result = sn.postorderTraversal(root);

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