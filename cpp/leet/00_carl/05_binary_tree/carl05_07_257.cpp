#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<int> path;
        postOrder(root, path);

        vector<std::string> results;
        for (auto& path : paths) {
            std::string item = "";
            for (int i = 0; i < path.size()-1; i++) {
                item += std::to_string(path[i]) + "->";
            }
            item += std::to_string(path[path.size()-1]);

            results.push_back(item);
        }
        return results;
    }

    void postOrder(TreeNode* node, vector<int>& path) {
        path.push_back(node->val);

        if (!node->left && !node->right) {
            paths.push_back(path);
        }

        if (node->left) {
            postOrder(node->left, path);
            path.pop_back();
        }
        if (node->right) {
            postOrder(node->right, path);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> paths;
};

void test1() {
    TreeNode* two = new TreeNode(2, nullptr, new TreeNode(5));
    TreeNode* root = new TreeNode(1, two, new TreeNode(3));

    Solution sn;
    vector<string> result = sn.binaryTreePaths(root);
    print(result);
    std::cout << ", expected:1->2->5,1->3" << std::endl;
}

int main() {
    test1();
//    test2();
//    test3();
    return 0;
}