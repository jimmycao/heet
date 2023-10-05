#include "../utils/header_tools.h"
#include "../utils/print_tools.h"

class Solution {  // 自底向上 + DP + 记忆
public:
    int noDescendSeqLen(vector<int>& nums) {
        vector<int> memo(nums.size(), 1);

        for (int c = 1; c < nums.size(); c++) {  // 遍历，把memo建立起来
            for (int p = 0; p < c; ++p) {
                if (nums[c] > nums[p]) {
                    memo[c] = std::max(memo[c], memo[p]+1);  // memo[c]基于之前的memo[p]去修改
                }
            }
            std::cout << "c:" << c << ", memo[c]:" << memo[c] << std::endl;
        }

        return memo[nums.size()-1];
    }
};

void test1() {
    vector<int> nums {1, 5, 3, 4, 6, 9, 7, 8};

    Solution sn;
    int result = sn.noDescendSeqLen(nums);
    std::cout << "result:" << result << std::endl;
}

int main() {
    test1();
    return 0;
}