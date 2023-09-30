#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Solution2 {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        return fib(n-1) + fib(n-2);
    }
};

class Solution {
private:
    std::vector<int> _results;

public:
    int fib(int n) {
        _results.reserve(n+1);

        _results.push_back(0);
        _results.push_back(1);


        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        for (int i = 2; i <=n; i++) {
            _results[i] = _results[i-1] + _results[i-2];
        }

        return _results[n];
    }
};

void test1() {
    std::cout << std::boolalpha;

    int n = 2;

    Solution s;
    int result = s.fib(n);
    std::cout << n << ", result:" << result << std::endl;
}

void test2() {
    std::cout << std::boolalpha;

    int n = 3;

    Solution s;
    int result = s.fib(n);
    std::cout << n << ", result:" << result << std::endl;
}

void test3() {
    std::cout << std::boolalpha;

    int n = 4;

    Solution s;
    int result = s.fib(n);
    std::cout << n << ", result:" << result << std::endl;
}

void test4() {
    std::cout << std::boolalpha;

    int n = 5;

    Solution s;
    int result = s.fib(n);
    std::cout << n << ", result:" << result << std::endl;
}

void test5() {
    std::cout << std::boolalpha;

    int n = 6;

    Solution s;
    int result = s.fib(n);
    std::cout << n << ", result:" << result << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}