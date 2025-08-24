#include <vector>

#include "../../cpp/utils/str_tools.h"

class Solution1 {
public:
    void moveZeroes(std::vector<int>& nums) 
    {
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                nums[left] = nums[right];
                left++;
            }
        }

        for (; left < nums.size(); left++) {
            nums[left] = 0;
        }
    }
};

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) 
    {
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                std::swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};

void test1()
{
    std::vector<int> nums {0, 1, 0, 3, 12};
    Solution sn;
    sn.moveZeroes(nums);
    std::cout << "result: " << StringTools::ToString(nums) << ", expected: [1, 3, 12, 0, 0]" << std::endl;
}

void test2()
{
    std::vector<int> nums {0};
    Solution sn;
    sn.moveZeroes(nums);
    std::cout << "result: " << StringTools::ToString(nums) << ", expected: [0]" << std::endl;
}

int main()
{
    test1();
    test2();
    return 0;
}