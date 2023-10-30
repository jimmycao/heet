#include "../../utils/print_tools.h"

#include "../../utils/tree.h"

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        int max = findMax(nums);

        auto it = std::find(nums.begin(), nums.end(), max);
        vector<int> prevNums(nums.begin(), it);
        vector<int> postNums(it+1, nums.end());

        return new TreeNode(max, constructMaximumBinaryTree(prevNums), constructMaximumBinaryTree(postNums));
    }

    int findMax(vector<int>& nums) {
        vector<int> tmp(nums);
        std::sort(tmp.begin(), tmp.end(), std::greater<int>());
        return tmp.front();
    }
};

void test1() {
    vector<int> nums {3,2,1,6,0,5};

    Solution sn;
    TreeNode* root = sn.constructMaximumBinaryTree(nums);
    vector<int> results = tranverse_tree_by_level(root);
    print(results);
    std::cout << ", expected:[6,3,5,null,2,0,null,null,1]" << std::endl;
}

int main() {
    test1();
//    test2();
    return 0;
}