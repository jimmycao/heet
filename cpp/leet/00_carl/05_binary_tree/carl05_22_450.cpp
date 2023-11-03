#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution { // 递归
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }

        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) { // 左右孩子均为空，直接删除
                delete root;
                return nullptr;
            } else if (root->left == nullptr) { // 左孩子为空，右孩子不为空，则删除该节点，让右孩子上升而成为自己的地位
                auto retNode = root->right;
                delete root;
                return retNode;
            } else if (root->right == nullptr) { // 与上相反，让左孩子上升而成为自己的地位
                auto retNode = root->left;
                delete root;
                return retNode;
            } else {            // 左右孩子均不为空，则寻找右子树的最左节点，然后把整个左子树挂在右子树的最左节点上，最终返回右孩子
                TreeNode* curr = root->right;
                while (curr->left != nullptr) {
                    curr = curr->left;
                }

                curr->left = root->left; // 要删除的节点(root)的左子树挂在curr(右子树的最左孩子的左孩子位置)
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

void test1() {
    TreeNode* three = new TreeNode(3, new TreeNode(2), new TreeNode(4));
    TreeNode* six = new TreeNode(6, nullptr, new TreeNode(7));
    TreeNode* root = new TreeNode(5, three, six);


    Solution sn;
    int key = 3;
    TreeNode* newTree = sn.deleteNode(root, key);
    vector<int> nodes = tranverse_tree_by_level(newTree);
    print(nodes);

    std::cout << ", expected:[5,4,6,2,null,null,7] or [5,2,6,null,4,null,7]" << std::endl;
}

int main() {
    test1();
    return 0;
}