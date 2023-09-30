#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <string_view>
#include <cassert>

#include <bits/stdc++.h>


class Solution {
public:
    int reverse(int x) {
        assert (x >= INT_MIN && x <= INT_MAX);

        long long result = 0;

        if (x == 0) {
            return 0;
        }

        unsigned long num = x > 0 ? x : std::abs(x);

        std::stringstream ss;
        ss << num;
        std::string str = ss.str();

        std::reverse(str.begin(), str.end());

        size_t pos = str.find_first_not_of('0');
        str = str.substr(pos);

        std::stringstream ss2;
        ss2 << str;
        
        ss2 >> result;

        // std::cout << result << std::endl;

        if (x < 0) {
            result *= -1;
        }

        if (result < INT_MIN || result > INT_MAX) {
            result = 0;
        }

        return result;
    }
};

void test1() {
    int x = 123;

    Solution s;
    int result = s.reverse(x);
    std::cout << "result:" << result << std::endl;
}

void test2() {
    int x = -123;

    Solution s;
    int result = s.reverse(x);
    std::cout << "result:" << result << std::endl;
}

void test3() {
    int x = 0;

    Solution s;
    int result = s.reverse(x);
    std::cout << "result:" << result << std::endl;
}

void test4() {
    int x = 1534236469;

    Solution s;
    int result = s.reverse(x);
    std::cout << "result:" << result << std::endl;
}

void test5() {
    int x = -2147483648;

    Solution s;
    int result = s.reverse(x);
    std::cout << "result:" << result << std::endl;
}

int main() {
    // test1();
    // test2();
    // test3();
    // test4();

    test5();

    return 0;
}