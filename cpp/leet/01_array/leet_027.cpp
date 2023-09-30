#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void print(const std::vector<int>& g);

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) {
                continue;
            }
            nums[j++] = nums[i];
        }

        return j;
    }
};

void print(const std::vector<int>& g) {
    std::for_each(g.begin(), g.end(), [](int i) { std::cout <<  i << " "; });
    std::cout << std::endl;
}

void print_with_len(const std::vector<int>& g, int len) {
    std::for_each(g.begin(), g.begin()+len, [](int i) { std::cout <<  i << " "; });
    std::cout << std::endl;
}

void common(std::vector<int>& nums, int val) {
    Solution sn;
    print(nums);
    int result = sn.removeElement(nums, val);
    std::cout << "result:" << result << std::endl;
    print_with_len(nums, result);
}

void test1() {
    std::vector<int> nums{3,2,2,3};
    int val = 3;
    common(nums, val);
    std::cout << "expected result:" << 2 << std::endl;
}

void test2() {
    std::vector<int> nums{0,1,2,2,3,0,4,2};
    int val = 2;
    common(nums, val);
    std::cout << "expected result:" << 5 << std::endl;
}


int main() {
    test1();
    test2();
    return 0;
}