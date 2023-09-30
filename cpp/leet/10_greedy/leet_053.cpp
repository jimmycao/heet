#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void print(const std::vector<int>& g);

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.size() == 1) { 
            return nums[0];
        }
        
        int result = nums[0];
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (tmp < 0 && tmp < nums[i]) {
                tmp = nums[i];
                if (result < tmp) {  //on tmp changed, we should refresh the result
                    result = tmp;
                }
                continue;
            }
            tmp += nums[i];

            if (result < tmp) {
                result = tmp;
            }
        }
        return result;
    }
};

void print(const std::vector<int>& g) {
    std::for_each(g.begin(), g.end(), [](int i) { std::cout <<  i << " "; });
    std::cout << std::endl;
}

void common(std::vector<int>& nums) {
    Solution sn;
    int result = sn.maxSubArray(nums);
    print(nums);
    std::cout << "result:" << result << std::endl;
}

void test1() {
    std::vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    common(nums);
    std::cout << "expected result:" << 6 << std::endl;
}

void test2() {
    std::vector<int> nums{1};
    common(nums);
    std::cout << "expected result:" << 1 << std::endl;
}

void test3() {
    std::vector<int> nums{5,4,-1,7,8};
    common(nums);
    std::cout << "expected result:" << 23 << std::endl;
}

void test4() {
    std::vector<int> nums{-2,-1};
    common(nums);
    std::cout << "expected result:" << -1 << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}