//
// Created by c00770977 on 2023/5/3.
//
#include "../../utils/tools.h"

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& inOrder, std::vector<int>& postOrder) {
        if (postOrder.empty()) {
            return nullptr;
        }

        int last = postOrder.back();

        // split the inOrder
        auto it = std::find(inOrder.begin(), inOrder.end(), last);

        std::vector<int> prevInOrder(inOrder.begin(), it);
//        print(prevInOrder);
        std::vector<int> postInorder(it+1, inOrder.end());
//        print(postInorder);

        std::vector<int> prevPostOrder(postOrder.begin(), postOrder.begin()+prevInOrder.size());
//        print(prevPostOrder);
        std::vector<int> postPostOrder(postOrder.begin()+prevInOrder.size(), postOrder.end()-1);
//        print(postPostOrder);

        return new TreeNode(last, buildTree(prevInOrder, prevPostOrder), buildTree(postInorder, postPostOrder));
    }
};

std::vector<int> levelTranverse(TreeNode* root) {
    std::vector<int> result;

    if (!root) {
        return {};
    }

    std::queue<TreeNode*> myQueue;
    myQueue.push(root);

    while (!myQueue.empty()) {
        TreeNode* tmp = myQueue.front();
        result.push_back(tmp->val);

        if (tmp->left) {
            myQueue.push(tmp->left);
        }
        if (tmp->right) {
            myQueue.push(tmp->right);
        }
        myQueue.pop();
    }

    return result;
}

void test1() {
    Solution sn;
    std::vector<int> inorder {9,3,15,20,7};
    std::vector<int> postorder {9,15,7,20,3};
    TreeNode* root = sn.buildTree(inorder, postorder);

    std::vector<int> result = levelTranverse(root);
    print(result);
}

int main() {
    test1();
    return 0;
}