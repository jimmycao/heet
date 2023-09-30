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

void print(std::vector<std::vector<int>>& nums) {
    std::for_each(nums.begin(), nums.end(), [](std::vector<int> num) {
        std::for_each(num.begin(), num.end(), [](int i) {std::cout << i << " ";});
        std::cout << std::endl;
    });
}

class TwoVecLess {
public:
    bool operator()(const std::vector<int>& a, const std::vector<int>& b) const {
        if (a.size() !=  b.size()) {
            return a.size() < b.size();
        }

        std::vector<int> aa(a);
        std::vector<int> bb(b);
        std::sort(aa.begin(), aa.end());
        std::sort(bb.begin(), bb.end());

        // print(aa);
        // print(bb);

        for (int i = 0; i < aa.size(); ++i) {
            if (aa[i] < bb[i]) {
                return true;
            }

            if (aa[i] > bb[i]) {
                return false;
            }
        }
        return false;
    }
};

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::set<std::vector<int>, TwoVecLess> idxResults;
        //1. idxResults
        std::unordered_map<int, std::vector<std::pair<int, int>>> sum2xyVec;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                int sum = nums[i] + nums[j];
                auto it = sum2xyVec.find(sum);
                if (it == sum2xyVec.end()) {
                    sum2xyVec[sum] = {std::pair<int, int>(i, j)};
                } else {
                    sum2xyVec[sum].push_back(std::pair<int, int>(i, j));
                }
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            int diff = 0 - nums[i];

            auto it = sum2xyVec.find(diff);
            if (it != sum2xyVec.end()) {
                for (auto& item : it->second) {
                    if (i != item.first && i != item.second) {
                        // std::cout << i << "," << item.first << "," << item.second << std::endl;
                        idxResults.insert({i, item.first, item.second});
                    }
                }
            }
        }

        // std::cout << "----------start-------------" << std::endl;
        // for (auto item : idxResults) {
        //     print(item);
        // }
        // std::cout << "----------end-------------" << std::endl;

        //2. elementResults
        std::set<std::vector<int>, TwoVecLess> elementResults;
        for (auto& item : idxResults) {
            elementResults.insert({nums[item[0]], nums[item[1]], nums[item[2]]});
        }

        //3. finalResults (std::set<std::vector<int>, TwoVecLess> => std::vector<std::vector<int>>)
        std::vector<std::vector<int>> finalResults;
        for (auto& item : elementResults) {
            finalResults.push_back({item[0], item[1], item[2]});
        }
        return finalResults;
    }
};

std::vector<std::vector<int>> common(std::vector<int>& nums) {
    Solution sn;
    return sn.threeSum(nums);
}

void test1() {
    std::vector<int> nums{-1,0,1,2,-1,-4};

    std::vector<std::vector<int>> results = common(nums);

    std::cout << "results:" << std::endl;
    print(results);
    std::cout << "expected:" << "[[-1,-1,2],[-1,0,1]]" << std::endl;
}

void test2() {
    std::vector<int> nums{0,1,1};

    std::vector<std::vector<int>> results = common(nums);

    std::cout << "results:" << std::endl;
    print(results);
    std::cout << "expected:" << "[]" << std::endl;
}

void test3() {
    std::vector<int> nums{0,0,0};

    std::vector<std::vector<int>> results = common(nums);

    std::cout << "results:" << std::endl;
    print(results);
    std::cout << "expected:" << "[[0,0,0]]" << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}