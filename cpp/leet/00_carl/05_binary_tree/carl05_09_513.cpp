#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> myQueue;
        myQueue.push(root);

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
                if (i == 0 && !tmp->left && !tmp->right) {
                    result = tmp->val;
                }
            }
        }

        return result;
    }

private:
    int result;
};

void test1() {
    TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    Solution sn;
    int result = sn.findBottomLeftValue(root);
    std::cout << "result:" << result;
    std::cout << ", expected:1" << std::endl;
}

void test2() {
    TreeNode* two = new TreeNode(2, new TreeNode(4), nullptr);
    TreeNode* five = new TreeNode(5, new TreeNode(7), nullptr);
    TreeNode* three = new TreeNode(3, five, new TreeNode(6));
    TreeNode* root = new TreeNode(1, two, three);

    Solution sn;
    int result = sn.findBottomLeftValue(root);
    std::cout << "result:" << result;
    std::cout << ", expected:7" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}