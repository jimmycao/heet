#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid = nums.size() / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        auto* tmp = root;
        for (int i = 0; i < mid; i++) {
            if (nums[i] > tmp->val) {
                tmp->right = new TreeNode(nums[i]);
                tmp = tmp->right;
            } else {
                tmp->left = new TreeNode(nums[i]);
                tmp = tmp->left;
            }
        }

        tmp = root;
        for (int i = mid+1; i < nums.size(); i++) {
            if (nums[i] > tmp->val) {
                tmp->right = new TreeNode(nums[i]);
                tmp = tmp->right;
            } else {
                tmp->left = new TreeNode(nums[i]);
                tmp = tmp->left;
            }
        }

        return root;
    }
};

void test1() {
    Solution sn;

    vector<int> nums {-10,-3,0,5,9};
    TreeNode* newTree = sn.sortedArrayToBST(nums);
    vector<int> nodes = tranverse_tree_by_level(newTree);

    print(nodes);
    std::cout << ", expected:[0,-3,9,-10,null,5]" << std::endl;
}

int main() {
    test1();
//    test2();
    return 0;
}