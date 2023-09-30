#include <climits>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <queue>
// #include <priority_queue>
#include <unordered_map>

void print(std::vector<int>& nums) {
    for_each(nums.begin(), nums.end(), [](int i) {
        std::cout << i << " ";
    });
    std::cout << std::endl;
}

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return {};
        }

        if (nums.size() < k) {
            std::sort(nums.begin(), nums.end(), std::greater<int>());
            return {nums[0]};
        }

        std::stack<int> myStack;
        for (int end = nums.size(); end - k >= 0; end--) {
            std::vector<int> tmpVec(&nums[end-k], &nums[end]);
            std::sort(tmpVec.begin(), tmpVec.end(), std::greater<int>());
            myStack.push(tmpVec[0]);
        }

        std::vector<int> result;
        while (!myStack.empty()) {
            result.push_back(myStack.top());
            myStack.pop();
        }

        return result;
    }
};

std::vector<int> common(std::vector<int>& nums, int k) {
    Solution sn;
    return sn.maxSlidingWindow(nums, k);
}

void test1() {
    std::vector<int> nums {1,3,-1,-3,5,3,6,7};
    int k = 3;

    std::vector<int> result = common(nums, k);
    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << "3,3,5,5,6,7" << std::endl;
}

void test2() {
    std::vector<int> nums {1};
    int k = 1;

    std::vector<int> result = common(nums, k);
    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << "1" << std::endl;
}

int main() {
    test1();
    test2();
    // test3();
    return 0;
}