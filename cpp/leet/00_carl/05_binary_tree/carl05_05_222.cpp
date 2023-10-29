#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution1 {
public:
    int countNodes(TreeNode* root) {
        return postOrder(root);
    }

    int postOrder(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int left = postOrder(node->left);
        int right = postOrder(node->right);
        return 1 + left + right;
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int sum = 0;
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        while (!myQueue.empty()) {
            size_t size = myQueue.size();
            for (int i = 0; i < size; i++) {
                auto tmp = myQueue.front();
                myQueue.pop();

                sum++;

                if (tmp->left) {
                    myQueue.push(tmp->left);
                }
                if (tmp->right) {
                    myQueue.push(tmp->right);
                }
            }
        }

        return sum;
    }
};

void test1() {
    TreeNode* two = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    TreeNode* three = new TreeNode(3, new TreeNode(6), nullptr);
    TreeNode* root = new TreeNode(1, two, three);

    Solution sn;
    int result = sn.countNodes(root);
    std::cout << "result:" << result << std::endl;
    std::cout << ", expected:6" << std::endl;
}

void test2() {
    TreeNode* root = nullptr;

    Solution sn;
    int result = sn.countNodes(root);
    std::cout << "result:" << result << std::endl;
    std::cout << ", expected:0" << std::endl;
}

void test3() {
    TreeNode* root = new TreeNode(1);

    Solution sn;
    int result = sn.countNodes(root);
    std::cout << "result:" << result << std::endl;
    std::cout << ", expected:1" << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}