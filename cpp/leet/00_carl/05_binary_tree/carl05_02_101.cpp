#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return false;
        }

        queue<TreeNode*> myQueue;
        if (root->left || root->right) {
            myQueue.push(root->left);
            myQueue.push(root->right);
        }

        while (!myQueue.empty()) {
            size_t size = myQueue.size();  // important
            vector<int> levelNums;
            for (int i = 0; i < size; i++) {
                auto ff = myQueue.front();
                myQueue.pop();
                if (ff) {
                    levelNums.push_back(ff->val);

                    myQueue.push(ff->left);  // important
                    myQueue.push(ff->right);

                } else {
                    levelNums.push_back(INT_MAX);
                }
            }

            vector<int> levelNumsCopy(levelNums);
            reverse(levelNumsCopy.begin(), levelNumsCopy.end());
            if (levelNums != levelNumsCopy) {
                return false;
            }
        }
        return true;
    }
};

void test1() {
    TreeNode* twoLeft = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    TreeNode* twoRight = new TreeNode(2, new TreeNode(4), new TreeNode(3));
    TreeNode* root = new TreeNode(1, twoLeft, twoRight);

    Solution sn;
    bool result = sn.isSymmetric(root);
    std::cout << std::boolalpha;
    std::cout << result << std::endl;
    std::cout << ", expected:true" << std::endl;
}

void test2() {
    TreeNode* twoLeft = new TreeNode(2, nullptr, new TreeNode(3));
    TreeNode* twoRight = new TreeNode(2, nullptr, new TreeNode(3));
    TreeNode* root = new TreeNode(1, twoLeft, twoRight);

    Solution sn;
    bool result = sn.isSymmetric(root);
    std::cout << std::boolalpha;
    std::cout << result << std::endl;
    std::cout << ", expected:false" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}