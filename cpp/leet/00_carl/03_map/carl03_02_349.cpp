#include "../../utils/print_tools.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) {
            return {};
        }

        unordered_set<int> nums1Set(nums1.begin(), nums1.end());

        unordered_set<int> resultSet;

        for (auto item : nums2) {
            if (nums1Set.find(item) != nums1Set.end()) {
                resultSet.insert(item);
            }
        }

        vector<int> result(resultSet.begin(), resultSet.end());

        return result;
    }
};

void test1() {
    vector<int> nums1 {1,2,2,1};
    vector<int> nums2 {2,2};

    Solution sn;
    vector<int> result = sn.intersection(nums1, nums2);
    print(result);
    std::cout << ", expected:[2]" << std::endl;
}

void test2() {
    vector<int> nums1 {4,9,5};
    vector<int> nums2 {9,4,9,8,4};

    Solution sn;
    vector<int> result = sn.intersection(nums1, nums2);
    print(result);
    std::cout << ", expected:[9,4]" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}