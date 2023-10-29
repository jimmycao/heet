#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode*> myQueue;
        myQueue.push(root);
        int step = 0;
        while (!myQueue.empty()) {
            size_t size = myQueue.size();
            for (int i = 0; i < size; i++) {
                auto tmp = myQueue.front();
                myQueue.pop();
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

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return getHeight(root);
    }

    //postOrder
    int getHeight(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int leftH = getHeight(node->left);
        int rightH = getHeight(node->right);
        return 1 + std::max(leftH, rightH);
    }
};

void test1() {
    TreeNode* twenty = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    TreeNode* root = new TreeNode(3, new TreeNode(9), twenty);

    Solution sn;
    int result = sn.maxDepth(root);
    std::cout << "result:" << result << std::endl;
    std::cout << ", expected:3" << std::endl;
}

void test2() {
    TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2));

    Solution sn;
    int result = sn.maxDepth(root);
    std::cout << "result:" << result << std::endl;
    std::cout << ", expected:2" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}