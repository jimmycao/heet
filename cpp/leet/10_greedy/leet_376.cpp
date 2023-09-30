#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void print(const std::vector<int>& g);

class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
        size_t size = nums.size();
        if (size == 1) {
            return 1;
        }

        int result = 1;

        int preDiff = 0;
        int postDiff = 0;

        for(int i = 0; i < size-1; ++i) {
            if (i == 0) {
               preDiff = 0;
            } 
            postDiff = nums[i+1] - nums[i];

            if ((preDiff <=0 && postDiff > 0) || 
                (preDiff >= 0 && postDiff < 0)) {
                result++;
                preDiff = postDiff;
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
    int result = sn.wiggleMaxLength(nums);
    print(nums);
    std::cout << "result:" << result << std::endl;
}

void test1() {
    std::vector<int> nums{1,7,4,9,2,5};
    common(nums);
    std::cout << "expected result:" << 6 << std::endl;
}

void test2() {
    std::vector<int> nums{1,17,5,10,13,15,10,5,16,8};
    common(nums);
    std::cout << "expected result:" << 7 << std::endl;
}

void test3() {
    std::vector<int> nums{1,2,3,4,5,6,7,8,9};
    common(nums);
    std::cout << "expected result:" << 2 << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}