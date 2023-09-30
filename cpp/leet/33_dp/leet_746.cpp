#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Solution {
private:
    std::vector<int> _minTotalCost;
public:
    int minCostClimbingStairs(const std::vector<int>& cost) {
        int steps = cost.size();
        _minTotalCost.reserve(steps + 1);

        for (int i = 0; i <= steps; i++) {
            if (i == 0 || i == 1) {
                _minTotalCost[i] = 0;
                continue;
            }

            _minTotalCost[i] = std::min(_minTotalCost[i-1] + cost[i-1], 
                                        _minTotalCost[i-2] + cost[i-2]);

        }
        return _minTotalCost[steps];
    }
};

void test1() {
    std::cout << std::boolalpha;

    std::vector<int> cost {10, 15, 20};

    Solution s;
    int result = s.minCostClimbingStairs(cost);

    std::for_each(cost.begin(), cost.end(),  [](int i) {std::cout << i << " ";});
    std::cout << ", result:" << result << std::endl;
}

void test2() {
    std::cout << std::boolalpha;

    std::vector<int> cost {1,100,1,1,1,100,1,1,100,1};

    Solution s;
    int result = s.minCostClimbingStairs(cost);

    std::for_each(cost.begin(), cost.end(),  [](int i) {std::cout << i << " ";});
    std::cout << ", result:" << result << std::endl;
}

int main() {
    // test1();
    test2();
    // test3();
    // test4();
    return 0;
}