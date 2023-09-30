#include <climits>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>

void print(std::vector<std::vector<int>>& nums) {
    std::for_each(nums.begin(), nums.end(), [](std::vector<int> num) {
        std::for_each(num.begin(), num.end(), [](int i) {std::cout << i << " ";});
        std::cout << std::endl;
    });
}

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        return {{}};
    }
};

std::vector<std::vector<int>> common(std::vector<int>& nums, int target) {
    Solution sn;
    return sn.fourSum(nums, target);
}

void test1() {
    std::vector<int> nums{1,0,-1,0,-2,2};
    int target = 0;

    std::vector<std::vector<int>> result = common(nums, target);

    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << "[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]" << std::endl;
}

int main() {
    test1();
    // test2();
    return 0;
}