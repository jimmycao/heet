#include "../utils/header_tools.h"
#include "../utils/print_tools.h"

/*
 f(n) = min { f(n-1), f(n-5), f(n-11) } + 1
 */

class Solution {  // 自底向上 + DP + 记忆
public:
    int moneyCount(int sum) {
        vector<int> memo(sum+1, -1);

        memo[0] = 0;

        for (int i = 1; i <= sum; i++) {
            int need = INT_MAX;
            if (i - 1 >= 0) {
                need = std::min(need, memo[i-1] + 1);
            }
            if (i - 5 >= 0) {
                need = std::min(need, memo[i-5] + 1);
            }
            if (i - 11 >= 0) {
                need = std::min(need, memo[i-11] + 1);
            }
            memo[i] = need;
            std::cout << "i:" << i <<", memo[i]:" << memo[i] << std::endl;
        }

        return memo[sum];
    }
};

void test1() {
    int sum = 15;

    Solution sn;
    int result = sn.moneyCount(sum);
    std::cout << "result:" << result << std::endl;
}

int main() {
    test1();
    return 0;
}