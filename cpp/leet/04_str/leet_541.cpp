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

class Solution {
public:
    std::string reverseStr(std::string s, int k) {
        std::string ss(s);
        int strides = ss.size() / (2 * k);
        for (size_t i = 0; i < strides; i++) {
            std::reverse(ss.begin() + i * 2 * k , ss.begin() + i * 2 * k + k);
        }

        if (s.size() - 2 * k * strides < k) {
            std::reverse(ss.begin() + 2 * k * strides, ss.end());
        } else {
            std::reverse(ss.begin() + 2 * k * strides, ss.begin() + 2 * k * strides + k);
        }

        return ss;
    }
};

std::string common(std::string s, int k) {
    Solution sn;
    return sn.reverseStr(s, k);
}

void test1() {
    std::string s = "abcdefg";
    int k = 2;

    std::string result = common(s, k);

    std::cout << "result:" << result << std::endl;
    std::cout << "expected:" << "bacdfeg" << std::endl;
}

void test2() {
    std::string s = "abcd";
    int k = 2;

    std::string result = common(s, k);

    std::cout << "result:" << result << std::endl;
    std::cout << "expected:" << "bacd" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}