#include "../../utils/tools.h"

class Solution {
public:
    void level(std::queue<TreeNode*>& nodeQueue, std::vector<std::vector<int>>& result) {
        std::vector<int> levelResult;
        std::queue<TreeNode*> subNodeQueue;

        if (nodeQueue.empty()) {
            return;
        }
        
        while (!nodeQueue.empty()) {
            TreeNode* node = nodeQueue.front();
            
            
            if (node->left) {
                levelResult.push_back(node->left->val);
                subNodeQueue.push(node->left);
            }
            if (node->right) {
                levelResult.push_back(node->right->val);
                subNodeQueue.push(node->right);
            }

            nodeQueue.pop();
        }

        if (!levelResult.empty()) {
            result.push_back(levelResult);
        }

        level(subNodeQueue, result);
        
    }

    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;

        std::queue<TreeNode*> nodeQueue;
        if (root) {
            result.push_back({root->val});
            nodeQueue.push(root);
            level(nodeQueue, result);
        }

        return result;
    }
};

void test1() {
    TreeNode* sevenNode = new TreeNode(7);
    TreeNode* fifteenNode = new TreeNode(15);
    TreeNode* twentyNode = new TreeNode(20, fifteenNode, sevenNode);
    TreeNode* nineNode = new TreeNode(9);
    TreeNode* root = new TreeNode(3, nineNode, twentyNode);

    Solution sn;
    std::vector<std::vector<int>> result = sn.levelOrder(root);

    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << "[3],[9,20],[15,7]" << std::endl;
}

void test2() {
    TreeNode* root = new TreeNode(1);

    Solution sn;
    std::vector<std::vector<int>> result = sn.levelOrder(root);

    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << 1 << std::endl;
}

void test3() {
    TreeNode* root = nullptr;

    Solution sn;
    std::vector<std::vector<int>> result = sn.levelOrder(root);

    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << " " << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}