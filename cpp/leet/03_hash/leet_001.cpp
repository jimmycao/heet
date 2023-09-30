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

void print(std::vector<int>& nums) {
    std::for_each(nums.begin(), nums.end(), [](int i) {std::cout << i << " ";});
    std::cout << std::endl;
}

// unordered_map
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num2idx;

        for (size_t i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];

            auto it = num2idx.find(diff);
            if (it == num2idx.end()) {
                // num2idx.insert({nums[i], i});
                num2idx.insert(std::pair<int, int>(nums[i], i));
            } else {
                // return {i, num2idx[diff]};
                return {(int)i, it->second};
            }
        }
        
        return {};
    }
};

// diff, then vector find
class Solution3 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> results;

        for (size_t i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            auto it = std::find(nums.begin()+i+1, nums.end(), diff);
            if (it != nums.end()) {
                results.push_back(i);
                results.push_back(it - nums.begin());
                return results;
            }
        }
        return {};
    }
};

// unordered_map
class Solution2 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        int l = nums.size();
        for(int i = 0; i< l; ++i){
            m[nums[i]] = i;
        }
        for(int i=0; i<l ;++i){
            if(m.count(target-nums[i]) && i != m[target-nums[i]]) {
                return {i, m[target-nums[i]]};
            }
        }
        return {};
    }
};

std::vector<int> common(std::vector<int>& nums1, int target) {
    Solution sn;
    return sn.twoSum(nums1, target);
}

void test1() {
    std::vector<int> nums1{2,7,11,15};
    int target = 9;

    std::vector<int> results = common(nums1, target);

    std::cout << "results:" << std::endl;
    print(results);
    std::cout << "expected:" << "0, 1" << std::endl;
}

void test2() {
    std::vector<int> nums1{3,2,4};
    int target = 6;

    std::vector<int> results = common(nums1, target);

    std::cout << "results:" << std::endl;
    print(results);
    std::cout << "expected:" << "1, 2" << std::endl;
}

void test3() {
    std::vector<int> nums1{3, 3};
    int target = 6;

    std::vector<int> results = common(nums1, target);

    std::cout << "results:" << std::endl;
    print(results);
    std::cout << "expected:" << "0, 1" << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}