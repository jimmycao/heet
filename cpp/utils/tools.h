#include <climits>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <numeric>
#include <queue>
#include <unordered_map>

void print(std::vector<int>& nums) {
    for_each(nums.begin(), nums.end(), [](int i) {
        std::cout << i << " ";
    });
    std::cout << std::endl;
}

void print(std::vector<std::vector<int>>& vecs) {
    for_each(vecs.begin(), vecs.end(), [](std::vector<int> nums) {
        for_each(nums.begin(), nums.end(), [](int i) {
            std::cout << i << " ";
        });
        std::cout << std::endl;
    });
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> levelTranverseTree(TreeNode* root) {
    std::vector<int> result;

    if (!root) {
        return {};
    }

    std::queue<TreeNode*> myQueue;
    myQueue.push(root);

    while (!myQueue.empty()) {
        TreeNode* tmp = myQueue.front();
        result.push_back(tmp->val);

        if (tmp->left) {
            myQueue.push(tmp->left);
        }
        if (tmp->right) {
            myQueue.push(tmp->right);
        }
        myQueue.pop();
    }

    return result;
}