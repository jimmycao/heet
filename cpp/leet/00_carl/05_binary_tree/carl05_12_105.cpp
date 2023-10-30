#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        int tmp = preorder.front();
        auto it = std::find(inorder.begin(), inorder.end(), tmp);

        vector<int> preInOrder(inorder.begin(), it);
        vector<int> postInOrder(it+1, inorder.end());

        vector<int> prePreOrder(preorder.begin()+1, preorder.begin()+1+preInOrder.size());
        vector<int> postPreOrder(preorder.begin()+1+preInOrder.size(), preorder.end());
        return new TreeNode(tmp,
                            buildTree(prePreOrder, preInOrder),
                            buildTree(postPreOrder, postInOrder));
    }
};

void test1() {
    vector<int> preorder {3,9,20,15,7};
    vector<int> inorder {9,3,15,20,7};

    Solution sn;
    TreeNode* root = sn.buildTree(preorder, inorder);
    std::cout << ", expected:[3,9,20,null,null,15,7]" << std::endl;
}

int main() {
    test1();
//    test2();
    return 0;
}