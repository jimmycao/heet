#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty()) {
            return nullptr;
        }

        int last = postorder.back();
        auto it = std::find(inorder.begin(), inorder.end(), last);

        std::vector<int> prevInOrder(inorder.begin(), it);
        std::vector<int> postInOrder(it+1, inorder.end());

        std::vector<int> prevPostOrder(postorder.begin(), postorder.begin()+prevInOrder.size());
        std::vector<int> postPostOrder(postorder.begin() + prevInOrder.size(), postorder.end()-1);

        return new TreeNode(last,
                            buildTree(prevInOrder, prevPostOrder),
                            buildTree(postInOrder, postPostOrder));
    }
};

void test1() {
    vector<int> inorder {9,3,15,20,7};
    vector<int> postorder {9,15,7,20,3};

    Solution sn;
    TreeNode* root = sn.buildTree(inorder, postorder);

    std::cout << ", expected:[5,4,11,2],[5,8,4,5]" << std::endl;
}

int main() {
    test1();
//    test2();
    return 0;
}