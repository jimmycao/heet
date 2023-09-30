#include "../../utils/tools.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        std::vector<std::vector<int>> result = levelOrder(root);
        // print(result);
        return result.size();
    }

    void _levelAccess(std::queue<TreeNode*>& nodeQueue, std::vector<std::vector<int>>& result) {
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

        _levelAccess(subNodeQueue, result);
        
    }

    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;

        std::queue<TreeNode*> nodeQueue;
        if (root) {
            result.push_back({root->val});
            nodeQueue.push(root);
            _levelAccess(nodeQueue, result);
        }

        return result;
    }
};


void test1() {
    TreeNode* fifteenNode = new TreeNode(15);
    TreeNode* sevenNode = new TreeNode(7);
    TreeNode* twentyNode = new TreeNode(20, fifteenNode, sevenNode);

    TreeNode* nineNode = new TreeNode(9);

    TreeNode* root = new TreeNode(3, nineNode, twentyNode);

    Solution sn;
    int result = sn.maxDepth(root);
    std::cout << "result:" << result << ", expected:" << 3 << std::endl;
}


int main() {
    test1();
    // test2();
    return 0;
}