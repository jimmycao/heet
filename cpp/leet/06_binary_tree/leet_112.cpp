//
// Created by c00770977 on 2023/5/2.
//
#include "../../utils/tools.h"

class Solution {
private:
    std::vector<std::vector<int>> paths_;

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        if (!root->left && !root->right) {
            if (root->val == targetSum) {
                return true;
            } else {
                return false;
            }
        }


        if (root->left) {
            std::vector<int> path;
            path.push_back(root->val);
            tranverse(root->left, path);
        }

        if (root->right) {
            std::vector<int> path;
            path.push_back(root->val);
            tranverse(root->right, path);
        }

//        print(paths_);
        for (auto path : paths_) {
            int sum = std::accumulate(path.begin(), path.end(), 0);
            if (sum == targetSum) {
                return true;
            }
        }

        return false;
    }

    void tranverse(TreeNode* node, std::vector<int> path) {
        path.push_back(node->val);

        if (!node->left && !node->right) {
            paths_.push_back(path);
        }

        if (node->left) {
            tranverse(node->left, path);
        }

        if (node->right) {
            tranverse(node->right, path);
        }
    }
};

void test1() {
    TreeNode* sevenNode = new TreeNode(7);
    TreeNode* twoNode = new TreeNode(2);
    TreeNode* elevenNode = new TreeNode(11, sevenNode, twoNode);

    TreeNode* fourLeftNode = new TreeNode(4, elevenNode, nullptr);

    TreeNode* oneNode = new TreeNode(1);
    TreeNode* fourRightNode = new TreeNode(4, nullptr, oneNode);

    TreeNode* thirteenNode = new TreeNode(13);

    TreeNode* eightNode = new TreeNode(8, thirteenNode, fourRightNode);
    TreeNode* root = new TreeNode(5, fourLeftNode, eightNode);

    Solution sn;
    int target = 22;
    bool result = sn.hasPathSum(root, target);
    std::cout << std::boolalpha;
    std::cout << "result:" << result << ", expected:" << true << std::endl;
}

void test2() {
    TreeNode* twoNode = new TreeNode(2);
    TreeNode* threeNode = new TreeNode(3);
    TreeNode* root = new TreeNode(1, twoNode, threeNode);

    Solution sn;
    int target = 5;
    bool result = sn.hasPathSum(root, target);
    std::cout << std::boolalpha;
    std::cout << "result:" << result << ", expected:" << false << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}