#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void print(const std::vector<int>& g);


class Solution {
public:
    int binSearch(std::vector<int>& nums, int start, int end, int target) {
        if (start > end) {
            return -1;
        }
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        } 

        if (nums[mid] < target) {
            start = mid + 1;
        } 

        if (nums[mid] > target) {
            end = mid - 1;
        }

        return binSearch(nums, start, end, target);
    }

    int search(std::vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        return binSearch(nums, start, end, target);
    }
};


void print(const std::vector<int>& g) {
    std::for_each(g.begin(), g.end(), [](int i) { std::cout <<  i << " "; });
    std::cout << std::endl;
}

void common(std::vector<int>& nums, int target) {
    Solution sn;
    int result = sn.search(nums, target);
    print(nums);
    std::cout << "result:" << result << std::endl;
}

void test1() {
    std::vector<int> nums{-1,0,3,5,9,12};
    int target = 9;
    common(nums, target);
    std::cout << "expected result:" << 4 << std::endl;
}

void test2() {
    std::vector<int> nums{-1,0,3,5,9,12};
    int target = 2;
    common(nums, target);
    std::cout << "expected result:" << -1 << std::endl;
}


int main() {
    test1();
    test2();
    return 0;
}