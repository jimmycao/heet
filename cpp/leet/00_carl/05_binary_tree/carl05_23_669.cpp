#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val > high) {
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }
        if (root->val < low) {
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
//class Solution {
//public:
//    TreeNode* trimBST(TreeNode* root, int low, int high) {
//        if (!root) {
//            return nullptr;
//        }
//
//        if (root->val < low || root->val > high) {
//            if (!root->left && !root->right) {
//                delete root;
//                return nullptr;
//            } else if (!root->left) {
//                auto tmp = root->right;
//                delete root;
//                return tmp;
//            } else if (!root->right) {
//                auto tmp = root->left;
//                delete root;
//                return tmp;
//            } else {
//                auto curr = root->right;
//                while (curr->left) {
//                    curr = curr->left;
//                }
//
//                curr->left = root->left;
//
//                auto tmp = root->right;
//                delete root;
//                return tmp;
//            }
//        }
//
//        if (root->val >= low && root->left) {
//            root->left = trimBST(root->left, low, high);
//        }
//
//        if (root->val <= high && root->right) {
//            root->right = trimBST(root->right, low, high);
//        }
//
//        return root;
//    }
//};

void test1() {
    TreeNode* root = new TreeNode(1, new TreeNode(0), new TreeNode(2));

    Solution sn;
    int low = 1;
    int high = 2;
    TreeNode* newTree = sn.trimBST(root, low, high);
    vector<int> nodes = tranverse_tree_by_level(newTree);
    print(nodes);

    std::cout << ", expected:[1,null,2]" << std::endl;
}

void test2() {
    TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2));

    Solution sn;
    int low = 2;
    int high = 4;
    TreeNode* newTree = sn.trimBST(root, low, high);
    vector<int> nodes = tranverse_tree_by_level(newTree);
    print(nodes);

    std::cout << ", expected:[2]" << std::endl;
}


int main() {
    test1();
    test2();
    return 0;
}