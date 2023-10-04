#include "../utils/header_tools.h"
#include "../utils/print_tools.h"

/*
Those who cannot remember the past are condemned to repeat it.
 Dynamic Programming
 */

class Solution1 {  // 递归
public:
    int Fabonacci(int n) {
        if (n <= 1) {
            return 1;
        }

        return Fabonacci(n-2) + Fabonacci(n-1);
    }
};


class Solution { // 递归 + memo
public:
    int Fabonacci(int n) {
        vector<int> memo(n+1, -1);
        return Fab(n, memo);
    }

    int Fab(int n, vector<int>& memo) {
        if (memo[n] != -1) {
            return memo[n];
        }

        if (n <= 1) {
            memo[n] = 1;
        } else {
            memo[n] = Fab(n-1, memo) + Fab(n-2, memo);
        }

        return memo[n];
    }
};

class Solution2 {  // bottom-up DP
public:
    int Fabonacci(int n) {
        vector<int> memo(n+1, -1);

        memo[0] = 1;
        memo[1] = 1;
        for (int i = 2; i <=n; ++i) {
            memo[i] = memo[i-2] + memo[i-1];
        }

        return memo[n];
    }
};

void test1() {
    int n = 4;

    Solution sn;
    int result = sn.Fabonacci(n);
    std::cout << "result:" << result << std::endl;
}

int main() {
    test1();
    return 0;
}