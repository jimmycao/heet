#include "../../utils/print_tools.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;

        auto it = std::find(nums.begin(), nums.end(), target);
        if (it != nums.end()) {
            first = it - nums.begin();
        }

        auto it2 = std::find(nums.rbegin(), nums.rend(), target);
        if (it2 != nums.rend()) {
            last = nums.rend() - it2 - 1;
        }

        return {first, last};
    }
};

void test1() {
    vector<int> nums {5,7,7,8,8,10};
    int target = 8;

    Solution sn;
    vector<int> result = sn.searchRange(nums, target);
    print(result);
}

void test2() {
    vector<int> nums {5,7,7,8,8,10};
    int target = 6;

    Solution sn;
    vector<int> result = sn.searchRange(nums, target);
    print(result);
}

void test3() {
    vector<int> nums {};
    int target = 0;

    Solution sn;
    vector<int> result = sn.searchRange(nums, target);
    print(result);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}