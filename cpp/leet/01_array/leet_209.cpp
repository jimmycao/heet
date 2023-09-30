#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void print(const std::vector<int>& g);

class Solution2 {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int minLen = nums.size() + 1;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] >= target) {
                return 1;
            }
            
            int total = nums[i];
            for (size_t j = i+1; j < nums.size(); j++) {
                if (nums[j] >= target) {
                    return 1;
                }

                total += nums[j];
                if (total >= target) {
                    int len = j - i + 1;
                    if (len < minLen) {
                        minLen = len;
                    }
                    break;
                }
            }
        }

        if (minLen == nums.size() + 1) {
            return 0;
        } else {
            return minLen;
        }
    }
};

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int minLen = nums.size() + 1;

        int i = 0;
        if (nums[i] >= target) {
            return 1;
        }
        
        int total = nums[i];
        for (size_t j = i+1; j < nums.size(); j++) {
            if (nums[j] >= target) {
                return 1;
            }

            total += nums[j];
            while (total >= target) {  // here to find the minimum len
                int len = j - i + 1;
                minLen = std::min(len, minLen);
                total -= nums[i];
                i++;
            }
        }

        if (minLen == nums.size() + 1) {
            return 0;
        } else {
            return minLen;
        }
    }
};

void print(const std::vector<int>& g) {
    std::for_each(g.begin(), g.end(), [](int i) { std::cout <<  i << " "; });
    std::cout << std::endl;
}

void common(int target, std::vector<int>& nums) {
    Solution sn;
    print(nums);
    int result = sn.minSubArrayLen(target, nums);
    std::cout << "result:" << result << std::endl;
}

void test1() {
    int target = 7;
    std::vector<int> nums{2,3,1,2,4,3};
    common(target, nums);
    std::cout << "expected:" << 2 << std::endl;
}

void test2() {
    int target = 4;
    std::vector<int> nums{1,4,4};
    common(target, nums);
    std::cout << "expected:" << 1 << std::endl;
}

void test3() {
    int target = 11;
    std::vector<int> nums{1,1,1,1,1,1,1,1};
    common(target, nums);
    std::cout << "expected:" << 0 << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}