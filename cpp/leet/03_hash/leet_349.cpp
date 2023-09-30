#include <climits>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>


void print(std::vector<int>& nums) {
    std::for_each(nums.begin(), nums.end(), [](int i) {std::cout << i << " ";});
    std::cout << std::endl;
}

// with set / unordered_set
class Solution2 {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> results;

        std::unordered_set<int> set1;
        std::unordered_set<int> set2;

        for (auto item : nums1) {
            set1.insert(item);
        }

        for (auto item :nums2) {
            set2.insert(item);
        }

        for (auto it = set1.begin(); it != set1.end(); ++it) {
            if (set2.find(*it) != set2.end()) {
                results.push_back(*it);
            }
        }

        return results;
    }
};

// with vector
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> results;

        std::vector<int> offset2count(1000, 0);

        for (size_t i = 0; i < nums1.size(); ++i) {
            offset2count[nums1[i]] = 1;
        }

        for (int i = 0; i < nums2.size(); ++i) {
            if (offset2count[nums2[i]] != 0) {
                results.insert(nums2[i]);
            }
        }

        std::vector<int> resultsVec;
        resultsVec.assign(results.begin(), results.end());
        return resultsVec;
    }
};


std::vector<int> common(std::vector<int>& nums1, std::vector<int>& nums2) {
    Solution sn;
    return sn.intersection(nums1, nums2);
}

void test1() {
    std::vector<int> nums1{1,2,2,1};
    std::vector<int> nums2{2,2};

    std::vector<int> results = common(nums1, nums2);

    std::cout << "results:" << std::endl;
    print(results);
    std::cout << "expected:" << "2" << std::endl;
}

void test2() {
    std::vector<int> nums1{4,9,5};
    std::vector<int> nums2{9,4,9,8,4};

    std::vector<int> results = common(nums1, nums2);

    std::cout << "results:" << std::endl;
    print(results);
    std::cout << "expected:" << "9, 4" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}