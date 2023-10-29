#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode*> myQueue;
        myQueue.push(root);

        int step = 1;
        while (!myQueue.empty()) {
            size_t size = myQueue.size();
            for (int i = 0; i < size; i++) {
                auto tmp = myQueue.front();
                myQueue.pop();

                if (!tmp->left && !tmp->right) {
                    return step;
                }

                if (tmp->left) {
                    myQueue.push(tmp->left);
                }
                if (tmp->right) {
                    myQueue.push(tmp->right);
                }
            }
            step++;
        }

        return step;
    }
};

class Solution2 {
public:
    int minDepth(TreeNode* root) {
        return getMinDepth(root);
    }

    int getMinDepth(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int left = getMinDepth(node->left);
        int right = getMinDepth(node->right);

        if (left == 0 && right != 0) {
            return 1 + right;
        }
        if (left != 0 && right == 0) {
            return 1 + left;
        }

        return 1 + min(left, right);
    }
};

void test1() {
    TreeNode* twenty = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    TreeNode* root = new TreeNode(3, new TreeNode(9), twenty);

    Solution sn;
    int result = sn.minDepth(root);
    std::cout << "result:" << result << std::endl;
    std::cout << ", expected:2" << std::endl;
}

void test2() {
    TreeNode* five = new TreeNode(5, nullptr, new TreeNode(6));
    TreeNode* four = new TreeNode(4, nullptr, five);
    TreeNode* three = new TreeNode(3, nullptr, four);
    TreeNode* two = new TreeNode(2, nullptr, three);

    Solution sn;
    int result = sn.minDepth(two);
    std::cout << "result:" << result << std::endl;
    std::cout << ", expected:5" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}