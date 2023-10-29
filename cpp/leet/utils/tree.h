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
        if (myQueue.front()->left) {
            myQueue.push(myQueue.front()->left);
        }

        if (myQueue.front()->right) {
            myQueue.push(myQueue.front()->right);
        }

        results.push_back(myQueue.front()->val);
        myQueue.pop();
    }

    return results;
}
