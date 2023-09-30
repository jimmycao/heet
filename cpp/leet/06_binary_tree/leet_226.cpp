#include "../../utils/tools.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            TreeNode* node = nodeQueue.front();
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;

            if (node->left) {
                nodeQueue.push(node->left);
            }
            if (node->right) {
                nodeQueue.push(node->right);
            }

            nodeQueue.pop();
        }
        
        return root;
    }

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
        if (!root) {
            return {{}};
        }

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
    TreeNode* oneNode = new TreeNode(1);
    TreeNode* threeNode = new TreeNode(3);
    TreeNode* twoNode = new TreeNode(2, oneNode, threeNode);
    
    TreeNode* sixNode = new TreeNode(6);
    TreeNode* nineNode = new TreeNode(9);
    TreeNode* sevenNode = new TreeNode(7, sixNode, nineNode);

    TreeNode* root = new TreeNode(4, twoNode, sevenNode);

    Solution sn;
    TreeNode* result = sn.invertTree(root);

    std::vector<std::vector<int>> final = sn.levelOrder(result);

    std::cout << "final:" << std::endl;
    print(final);
    std::cout << "expected:" << "[4],[7,2],[9,6,3,1]" << std::endl;
}

void test2() {
    TreeNode* oneNode = new TreeNode(1);
    TreeNode* threeNode = new TreeNode(3);
    TreeNode* root = new TreeNode(2, oneNode, threeNode);

    Solution sn;
    TreeNode* result = sn.invertTree(root);

    std::vector<std::vector<int>> final = sn.levelOrder(result);

    std::cout << "final:" << std::endl;
    print(final);
    std::cout << "expected:" << "[2],[3,1]" << std::endl;
}

void test3() {
    TreeNode* root = nullptr;

    Solution sn;
    TreeNode* result = sn.invertTree(root);

    std::vector<std::vector<int>> final = sn.levelOrder(result);

    std::cout << "final:" << std::endl;
    print(final);
    std::cout << "expected:" << "[]" << std::endl;
}

int main() {
    // test1();
    // test2();
    test3();
    return 0;
}