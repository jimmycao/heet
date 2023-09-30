#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <iterator>
#include <string>


class Solution {
public:
    std::vector<int> mergeTwoVec(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> merged;

        if (nums1.size() == 0) {
            return std::move(nums2);
        } 
        
        if (nums2.size() == 0) {
            return std::move(nums1);
        } 
        
      
        int i = 0, j = 0; 
        while (i <= nums1.size()-1 && j <= nums2.size()-1) {
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i++]);
            } else {
                merged.push_back(nums2[j++]);
            }
        }

        if (i == nums1.size()) {
            while (j <= nums2.size()-1) {
                merged.push_back(nums2[j++]);
            }
        }

        if (j == nums2.size()) {
            while (i <= nums1.size()-1) {
                merged.push_back(nums1[i++]);
            }
        }

        return std::move(merged);
    }

    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> merged = mergeTwoVec(nums1, nums2);

        // std::for_each(merged.begin(), merged.end(), [](auto it) {std::cout << it << " ";});
        // std::cout << std::endl;

        size_t size = merged.size();
        int mid = size / 2;
        if (size % 2 != 0) {
            return merged[mid] / 1.0;
        } else {
            return (merged[mid-1] + merged[mid]) / 2.0;
        }
    }
};

void test1() {
    std::vector<int> v1{1, 3};
    std::vector<int> v2{2};

    Solution s;
    double result = s.findMedianSortedArrays(v1, v2);
    std::cout << "result:" << result << std::endl;
}

void test2() {
    std::vector<int> v1{1, 2};
    std::vector<int> v2{3, 4};

    Solution s;
    double result = s.findMedianSortedArrays(v1, v2);
    std::cout << "result:" << result << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}