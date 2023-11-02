#include "header_tools.h"

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void tranverse_in_order(TreeNode* root, vector<int>& results)
{
    if (root->left) {
        tranverse_in_order(root->left, results);
    }
    results.push_back(root->val);
    if (root->right) {
        tranverse_in_order(root->right, results);
    }
}


vector<int> tranverse_tree_by_level(TreeNode* root)
{
    if (!root) {
        return {};
    }

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

            if (tmp && (tmp->left || tmp->right)) {
                myQueue.push(tmp->left);
                myQueue.push(tmp->right);
            }
        }
    }

    return results;
}

