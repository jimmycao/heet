#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution { // 中序遍历; 得到的数组升序排列
public:
    long long maxVal = LONG_MIN;
    bool isValidBST(TreeNode *root) {
        if (!root) {
            return true;
        }

        bool left = isValidBST(root->left);

        // 中序遍历，验证是否从小到大
        if (maxVal < root->val) {
            maxVal = root->val;
        } else {
            return false;
        }

        bool right = isValidBST(root->right);
        return left && right;
    }
};

class Solution1 { // 中序遍历; 得到的数组升序排列
public:
    bool isValidBST(TreeNode* root) {
        results.clear();
        inOrder(root);

        for (int i = 1; i < results.size(); i++) {
            if (results[i-1] >= results[i]) {
                return false;
            }
        }

        return true;
    }
private:
    void inOrder(TreeNode* node) {
        if (!node) {
            return;
        }
        if (node->left) {
            inOrder(node->left);
        }
        results.push_back(node->val);
        if (node->right) {
            inOrder(node->right);
        }
    }

    vector<int> results;
};

void test1() {
    TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    Solution sn;
    bool result = sn.isValidBST(root);
    std::cout << boolalpha << result;
    std::cout << ", expected:true" << std::endl;
}

void test2() {
    TreeNode* four = new TreeNode(4, new TreeNode(3), new TreeNode(6));
    TreeNode* root = new TreeNode(5, new TreeNode(1), four);

    Solution sn;
    bool result = sn.isValidBST(root);
    std::cout << boolalpha << result;
    std::cout << ", expected:false" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}