#include <climits>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>

class Solution {
public:
    int fourSumCount(std::vector<int>& nums1, 
                     std::vector<int>& nums2, 
                     std::vector<int>& nums3, 
                     std::vector<int>& nums4) {
        int total = 0;
        int size = nums1.size();

        std::unordered_map<int, int> sum2count;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int sum = nums1[i] + nums2[j];
                auto it = sum2count.find(sum);
                if (it == sum2count.end()) {
                    sum2count.insert(std::pair<int, int>(sum, 1));
                } else {
                    sum2count[sum]++;
                }
            }
        }

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int diff = 0 - nums3[i] - nums4[j];
                auto it = sum2count.find(diff);
                if (it != sum2count.end()) {
                    total += it->second;
                }
            }
        }
        return total;
    }
};


class Solution2 {
public:
    void mergeTowVec(std::vector<int>& nums1, 
                     std::vector<int>& nums2, 
                     std::unordered_map<int, std::vector<std::pair<int, int>>>& sum2pair12) {
        int size = nums1.size();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int sum = nums1[i] + nums2[j];
                auto it = sum2pair12.find(sum);
                if (it == sum2pair12.end()) {
                    sum2pair12.insert({sum, {std::pair<int, int>({i, j})}});
                } else {
                    sum2pair12[sum].push_back(std::pair<int, int>({i, j}));
                }
            }
        }
    }

    int fourSumCount(std::vector<int>& nums1, 
                     std::vector<int>& nums2, 
                     std::vector<int>& nums3, 
                     std::vector<int>& nums4) {
        int total = 0;

        std::unordered_map<int, std::vector<std::pair<int, int>>> sum2pair12;
        std::unordered_map<int, std::vector<std::pair<int, int>>> sum2pair34;

        mergeTowVec(nums1, nums2, sum2pair12);
        mergeTowVec(nums3, nums4, sum2pair34);

        for (auto item : sum2pair12) {
            int diff = 0 - item.first;
            auto it34 = sum2pair34.find(diff);
            if (it34 != sum2pair34.end()) {
                total += item.second.size() * it34->second.size(); 
            }
        }

        return total;
    }
};

int common(std::vector<int>& nums1, 
                     std::vector<int>& nums2, 
                     std::vector<int>& nums3, 
                     std::vector<int>& nums4) {
    Solution sn;
    return sn.fourSumCount(nums1, nums2, nums3, nums4);
}

void test1() {
    std::vector<int> nums1{1,2};
    std::vector<int> nums2{-2,-1};
    std::vector<int> nums3{-1,2};
    std::vector<int> nums4{0,2};

    int result = common(nums1, nums2, nums3, nums4);

    std::cout << "result:" << result << std::endl;
    std::cout << "expected:" << "2" << std::endl;
}

void test2() {
    std::vector<int> nums1{0};
    std::vector<int> nums2{0};
    std::vector<int> nums3{0};
    std::vector<int> nums4{0};

    int result = common(nums1, nums2, nums3, nums4);

    std::cout << "result:" << result << std::endl;
    std::cout << "expected:" << "1" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}