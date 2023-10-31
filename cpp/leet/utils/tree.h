#include "header_tools.h"

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> tranverse_tree_by_level(TreeNode* root)
{
    vector<int> results;

    queue<TreeNode*> myQueue;
    myQueue.push(root);
    while (!myQueue.empty()) {
        size_t size = myQueue.size();
        for (int i = 0; i < size; i++) {
            auto tmp = myQueue.front();
            myQueue.pop();
            if (!tmp) {
                results.push_back(INT_MAX);
            } else {
                results.push_back(tmp->val);
            }

            if (tmp->left || tmp->right) {
                myQueue.push(tmp->left);
                myQueue.push(tmp->right);
            }
        }
    }

    return results;
}

