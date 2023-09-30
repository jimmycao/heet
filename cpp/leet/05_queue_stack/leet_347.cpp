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
#include <unordered_map>

void print(std::vector<int>& nums) {
    for_each(nums.begin(), nums.end(), [](int i) {
        std::cout << i << " ";
    });
    std::cout << std::endl;
}

struct Node {
    int num;
    int count;
}; 

struct MyGreater {
    bool operator() (const Node& a, const Node& b) {
        return a.count > b.count;
    }
};

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> num2count;
        for (auto& num : nums) {
            auto it = num2count.find(num);
            if (it != num2count.end()) {
                num2count[num]++;
            } else {
                num2count.insert(std::pair<int, int>(num, 1));
                // num2count[num] = 1;
            }
        }

        std::vector<Node> nodes;
        for (auto& item : num2count) {
            Node node {item.first, item.second};
            nodes.push_back(node);
        }
        
        // std::sort(nodes.begin(), nodes.end(), [](Node& a, Node& b) {
        //     return a.count > b.count;
        // });
        std::sort(nodes.begin(), nodes.end(), MyGreater());

        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(nodes[i].num);
        }

        return result;
    }
};

std::vector<int> common(std::vector<int>& nums, int k) {
    Solution sn;
    return sn.topKFrequent(nums, k);
}

void test1() {
    std::vector<int> nums {1,1,1,2,2,3};
    int k = 2;

    std::vector<int> result = common(nums, k);
    std::cout << "result:" << std::endl;
    print(result);
    std::cout << "expected:" << "1,2" << std::endl;
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
    return 0;
}