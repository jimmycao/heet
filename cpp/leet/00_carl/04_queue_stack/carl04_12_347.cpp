#include "../../utils/print_tools.h"

struct MyCompare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
    {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> myQueue;
        unordered_map<int, int> num2count;
        for (auto & item : nums) {
            num2count[item]++;
        }

        for (auto& item : num2count) {
            myQueue.push({item.first, item.second});
            if (myQueue.size() > k) {
                myQueue.pop();
            }
        }

        vector<int> results;
        while (!myQueue.empty()) {
            results.push_back(myQueue.top().first);
            myQueue.pop();
        }

        return results;
    }
};

void test1() {
    vector<int> nums {1,1,1,2,2,3};
    int k = 2;

    Solution sn;
    vector<int> result = sn.topKFrequent(nums, k);
    print(result);
    std::cout << ", expected:[1,2]" << std::endl;
}

void test2() {
    vector<int> nums {1};
    int k = 1;

    Solution sn;
    vector<int> result = sn.topKFrequent(nums, k);
    print(result);
    std::cout << ", expected:[1]" << std::endl;
}

int main() {
    test1();
//    test2();
    return 0;
}