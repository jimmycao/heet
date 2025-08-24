#include <vector>
#include <algorithm>

#include "../../cpp/utils/str_tools.h"

// 超时
class Solution1 {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());

        std::set<std::vector<int>> ss;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            for (int j = i+1; j < nums.size(); j++) {
                int diff = 0 - nums[i] - nums[j];
                auto it = std::find(nums.begin() + j + 1, nums.end(), diff);
                if (it != nums.end()) {
                    ss.insert({nums[i], nums[j], *it});
                }
            }
        }   
        
        std::vector<std::vector<int>> results(ss.begin(), ss.end());
        return results;
    }
};

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {   
        std::vector<std::vector<int>> results;

        std::sort(nums.begin(), nums.end());
        

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int right = nums.size() - 1;
            for (int j = i+1; j < nums.size(); j++) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }

                while (j < right && nums[i] + nums[j] + nums[right] > 0) {
                    right--;
                }

                if (j == right) {
                    break;
                }

                if (nums[i] + nums[j] + nums[right] == 0) {
                    results.push_back({nums[i], nums[j], nums[right]});
                }
            }
        }

        return results;
    }
};

void test1()
{
    Solution sn;
    std::vector<int> nums {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result = sn.threeSum(nums);
    std::cout << "results:" << std::endl;
    for (auto& vec : result) {
        std::cout << StringTools::ToString(vec) << std::endl;
    }
    std::cout << "expected: [[-1,-1,2],[-1,0,1]]" << std::endl;
}


void test2()
{
    Solution sn;
    std::vector<int> nums {0, 1, 1};
    std::vector<std::vector<int>> result = sn.threeSum(nums);
    std::cout << "results:" << std::endl;
    for (auto& vec : result) {
        std::cout << StringTools::ToString(vec) << std::endl;
    }
    std::cout << "expected: []" << std::endl;
}

void test3()
{
    Solution sn;
    std::vector<int> nums {0, 0, 0};
    std::vector<std::vector<int>> result = sn.threeSum(nums);
    std::cout << "results:" << std::endl;
    for (auto& vec : result) {
        std::cout << StringTools::ToString(vec) << std::endl;
    }
    std::cout << "expected: [[0,0,0]]" << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
