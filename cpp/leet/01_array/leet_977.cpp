#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void print(const std::vector<int>& g);

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> results(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            results[i] = nums[i] * nums[i];
        }

        std::sort(results.begin(), results.end());
        return results;
    }
};

void print(const std::vector<int>& g) {
    std::for_each(g.begin(), g.end(), [](int i) { std::cout <<  i << " "; });
    std::cout << std::endl;
}

void common(std::vector<int>& nums) {
    Solution sn;
    print(nums);
    std::vector<int> results = sn.sortedSquares(nums);
    print(results);
}

void test1() {
    std::vector<int> nums{-4,-1,0,3,10};
    common(nums);
}

void test2() {
    std::vector<int> nums{-7,-3,2,3,11};
    common(nums);
}

int main() {
    // test1();
    test2();
    return 0;
}