#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Solution2 {
public:
    int climbStairs(int n) {
        if (n < 1 || n > 45) {
            std::cerr << "input error" << std::endl;
            return -1;
        }

        if (n == 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        return climbStairs(n-1) + climbStairs(n-2);
    }
};

class Solution {
private:
    std::vector<int> _results;
public:
    int climbStairs(int n) {
        if (n < 1 || n > 45) {
            std::cerr << "input error" << std::endl;
            return -1;
        }

        _results.reserve(n+1);

        _results[1] = 1;

        if (n > 1) {
            _results[2] = 2;
        }

        for (int i = 3; i <=n ; ++i) {
            _results[i] = _results[i-1] + _results[i-2];
        }

        return _results[n];
    }
};

void test1() {
    std::cout << std::boolalpha;

    int n = 1;

    Solution s;
    int result = s.climbStairs(n);
    std::cout << n << ", result:" << result << std::endl;
}

void test2() {
    std::cout << std::boolalpha;

    int n = 2;

    Solution s;
    int result = s.climbStairs(n);
    std::cout << n << ", result:" << result << std::endl;
}

void test3() {
    std::cout << std::boolalpha;

    int n = 3;

    Solution s;
    int result = s.climbStairs(n);
    std::cout << n << ", result:" << result << std::endl;
}

void test4() {
    std::cout << std::boolalpha;

    int n = 4;

    Solution s;
    int result = s.climbStairs(n);
    std::cout << n << ", result:" << result << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}