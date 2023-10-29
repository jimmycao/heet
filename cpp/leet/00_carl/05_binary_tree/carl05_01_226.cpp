#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        queue<TreeNode*> myQueue;
        myQueue.push(root);
        while(!myQueue.empty()) {
            TreeNode* top = myQueue.front();
            myQueue.pop();

            if (top->left || top->right) {
                std::swap(top->left, top->right);
            }

            if (top->left) {
                myQueue.push(top->left);
            }
            if (top->right) {
                myQueue.push(top->right);
            }
        }
        return root;
    }
};

class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

void test1() {
    TreeNode* two = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    TreeNode* seven = new TreeNode(7, new TreeNode(6), new TreeNode(9));
    TreeNode* root = new TreeNode(4, two, seven);

    Solution sn;
    TreeNode* head = sn.invertTree(root);
    vector<int> results = tranverse_tree_by_level(head);
    print(results);
    std::cout << ", expected:[4,7,2,9,6,3,1]" << std::endl;
}

void test2() {
    TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    Solution sn;
    TreeNode* head = sn.invertTree(root);
    vector<int> results = tranverse_tree_by_level(head);
    print(results);
    std::cout << ", expected:[2,3,1]" << std::endl;
}

void test3() {
    TreeNode* root = nullptr;

    Solution sn;
    TreeNode* head = sn.invertTree(root);
    vector<int> results = tranverse_tree_by_level(head);
    print(results);
    std::cout << ", expected:[2,3,1]" << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}