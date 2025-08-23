#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#include "../../cpp/utils/str_tools.h"

// 双指针，暴力法
class Solution1 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] == diff) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// 单指针，求差法，向前查
class Solution2 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            // 注意：这里要 nums.begin() + i + 1
            auto it = std::find(nums.begin() + i + 1, nums.end(), diff);
            if (it != nums.end()) {
                return {i, (int)(it - nums.begin())};
            }
        }
        return {};
    }
};

// 单指针，求差法，向后查
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::map<int, int> num2idx;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (num2idx.count(diff) != 0) {
                return {i, num2idx[diff]};
            } else {
                num2idx[nums[i]] = i;
            }
        }

        return {};
    }
};

void test1()
{
    Solution sn;
    std::vector<int> nums {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = sn.twoSum(nums, target);
    std::cout << "result:" << StringTools::ToString(result) << ", expected:" << "[0, 1]" << std::endl;
}

void test2()
{
    Solution sn;
    std::vector<int> nums {3, 2, 4};
    int target = 6;
    std::vector<int> result = sn.twoSum(nums, target);
    std::cout << "result:" << StringTools::ToString(result) << ", expected:" << "[1, 2]" << std::endl;
}

int main()
{
   test1();
   test2();
   return 0;
}