#include "../../utils/tools.h"

class Solution {
public:
    void preOrder(TreeNode* root, std::vector<int>& result) {
        if (root) {
            result.push_back(root->val);
        }
        if (root->left) {
            preOrder(root->left, result);
        }
        if (root->right) {
            preOrder(root->right, result);
        }
    }

    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (root) {
            preOrder(root, result);
        }
        return result;
    }
};

void test1() {
    TreeNode* threeNode = new TreeNode(3);
    TreeNode* twoNode = new TreeNode(2, threeNode, nullptr);
    TreeNode* root = new TreeNode(1, nullptr, twoNode);


    Solution sn;
    std::vector<int> result = sn.preorderTraversal(root);

    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << "1,2,3" << std::endl;
}

void test2() {
    TreeNode* root = nullptr;

    Solution sn;
    std::vector<int> result = sn.preorderTraversal(root);

    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << " " << std::endl;
}

void test3() {
    TreeNode* root = new TreeNode(1);

    Solution sn;
    std::vector<int> result = sn.preorderTraversal(root);

    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << 1 << std::endl;
}

void test4() {
    TreeNode* twoNode = new TreeNode(2);
    TreeNode* root = new TreeNode(1, twoNode, nullptr);

    Solution sn;
    std::vector<int> result = sn.preorderTraversal(root);

    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << "1 2" << std::endl;
}

void test5() {
    TreeNode* twoNode = new TreeNode(2);
    TreeNode* root = new TreeNode(1, nullptr, twoNode);

    Solution sn;
    std::vector<int> result = sn.preorderTraversal(root);

    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << "1 2" << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}