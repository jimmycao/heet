//
// Created by c00770977 on 2023/5/2.
//
#include "../../utils/tools.h"

class Solution {
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<TreeNode*> paths;
        std::vector<std::string> result;
        tranverse(root, paths, result);
        return result;
    }

    void tranverse(TreeNode* node, std::vector<TreeNode*>& paths, std::vector<std::string>& result) {
        paths.push_back(node);

        if (!node->left && !node->right) {
            std::string tmp = "";
            for (size_t i = 0; i < paths.size(); ++i) {
                tmp += std::to_string(paths[i]->val);
                if (i != paths.size()-1) {
                    tmp += "->";
                }
            }
            result.push_back(tmp);
        }

        if (node->left) {
            tranverse(node->left, paths, result);
            paths.pop_back();
        }

        if (node->right) {
            tranverse(node->right, paths, result);
            paths.pop_back();
        }

    }
};

void test1() {
    TreeNode* fiveNode = new TreeNode(5);
    TreeNode* twoNode = new TreeNode(2, nullptr, fiveNode);

    TreeNode* threeNode = new TreeNode(3);
    TreeNode* root = new TreeNode(1, twoNode, threeNode);

    Solution sn;
    std::vector<std::string> paths = sn.binaryTreePaths(root);
    for_each(paths.begin(), paths.end(), [](std::string str) {
        std::cout << str << std::endl;
    });
}

void test2() {
    TreeNode* root = new TreeNode(1);

    Solution sn;
    std::vector<std::string> paths = sn.binaryTreePaths(root);
    for_each(paths.begin(), paths.end(), [](std::string str) {
        std::cout << str << std::endl;
    });
}

int main() {
    test1();
    test2();
    return 0;
}