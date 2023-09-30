//
// Created by c00770977 on 2023/5/3.
//
#include "../../utils/tools.h"

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        int max = findMax(nums);
        auto it = std::find(nums.begin(), nums.end(), max);
        std::vector<int> prevHalf(nums.begin(), it);
        std::vector<int> postHalf(it+1, nums.end());

        return new TreeNode(max, constructMaximumBinaryTree(prevHalf), constructMaximumBinaryTree(postHalf));
    }

    int findMax(std::vector<int>& nums) {
        std::vector<int> tmp(nums);
        std::sort(tmp.begin(), tmp.end(), std::greater<int>());
        return tmp.front();
    }
};

void test1() {
    std::vector<int> nums {3,2,1,6,0,5};
    Solution sn;
    TreeNode* result = sn.constructMaximumBinaryTree(nums);
    std::vector<int> levels = levelTranverseTree(result);
    print(levels);
}

int main() {
    test1();
    return 0;
}