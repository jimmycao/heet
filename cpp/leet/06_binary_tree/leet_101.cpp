#include "../../utils/tools.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        std::vector<std::vector<int>> levelNums = levelOrder(root);

        for (auto& nums : levelNums) {
            bool result = isSymmetricVec(nums);
            if (!result) {
                return false;
            }
        }
        return true;
    }

    bool isSymmetricVec(std::vector<int>& nums) {
        for (int i = 0; i < nums.size()/2; ++i) {
            if (nums[i] != nums[nums.size()-i-1]) {
                return false;
            }
        }
        return true;
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
            } else {
                levelResult.push_back(INT_MIN);  // fill padding
            }

            if (node->right) {
                levelResult.push_back(node->right->val);
                subNodeQueue.push(node->right);
            } else {
                levelResult.push_back(INT_MIN); // fill padding
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
    TreeNode* threeNode = new TreeNode(3);
    TreeNode* fourNode = new TreeNode(4);
    TreeNode* twoNode = new TreeNode(2, threeNode, fourNode);

    TreeNode* fourNodeRight = new TreeNode(4);
    TreeNode* threeNodeRight = new TreeNode(3);
    TreeNode* twoNodeRight = new TreeNode(2, fourNodeRight, threeNodeRight);
    

    TreeNode* root = new TreeNode(1, twoNode, twoNodeRight);

    Solution sn;
    bool result = sn.isSymmetric(root);
    std::cout << std::boolalpha;
    std::cout << "result:" << result << ", expected:" << true << std::endl;
}

void test2() {
    TreeNode* threeNode = new TreeNode(3);
    TreeNode* twoNode = new TreeNode(2, nullptr, threeNode);
    
    TreeNode* threeNodeRight = new TreeNode(3);
    TreeNode* twoNodeRight = new TreeNode(2, nullptr, threeNode);

    TreeNode* root = new TreeNode(1, twoNode, twoNodeRight);

    Solution sn;
    bool result = sn.isSymmetric(root);
    std::cout << std::boolalpha;
    std::cout << "result:" << result << ", expected:" << false << std::endl;
}


int main() {
    test1();
    test2();
    return 0;
}