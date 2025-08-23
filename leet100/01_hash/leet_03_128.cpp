#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>

#include "../../cpp/utils/str_tools.h"

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_map<int, int> num2flag;
        for (auto& num : nums) {
            num2flag[num] = 1;
        }

        int longest = 0;
        for (auto& p : num2flag) {
            if (p.second) {
                int value = p.first;
                int length = 1;
                for (int i = 1; num2flag.count(value-i) && num2flag[value-i]; i++) {
                    length++;
                    num2flag[value-i] = 0;
                }
                for (int i = 1; num2flag.count(value+i) && num2flag[value+i]; i++) {
                    length++;
                    num2flag[value+i] = 0;
                }
                longest = std::max(longest, length);
            }
        }
        return longest;
    }
};

class Solution1 {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        std::set<int> unique(nums.begin(), nums.end());
        std::vector<int> unique_nums(unique.begin(), unique.end());
        std::sort(unique_nums.begin(), unique_nums.end());

        if (unique_nums.size() == 1) {
            return 1;
        }

        int longest = 1;

        int prev = unique_nums[0];  // 线性扫描
        int count = 1;
        for (int i = 1; i < unique_nums.size(); i++) {
            if (unique_nums[i] == prev + 1) {
                prev++;
                count++;
                if (count > longest) {
                    longest = count;
                }
            } else {
                prev = unique_nums[i];
                count = 1;
            }
        }
        
        return longest;
    }
};

void test1()
{
    std::vector<int> nums {100, 4, 200, 1, 3, 2};
    Solution sn;
    int result = sn.longestConsecutive(nums);
    std::cout << "result: " << result << ", expected: 4" << std::endl; 
}

void test2()
{
    std::vector<int> nums {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    Solution sn;
    int result = sn.longestConsecutive(nums);
    std::cout << "result: " << result << ", expected: 9" << std::endl; 
}

int main()
{
    // test1();
    test2();
    return 0;
}

