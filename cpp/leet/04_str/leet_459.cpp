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
    bool repeatedSubstringPattern(const std::string& s) {
        size_t len = s.size();

        for (size_t stepLen = 1; stepLen <= len / 2; ++stepLen) {
            if (len % stepLen != 0) {
                continue;
            }

            int steps = len / stepLen;
            std::string sub = s.substr(0, stepLen);
            for (int i = 1; i < steps; i++) {
                std::string nextSub = s.substr(i * stepLen, stepLen);
                if (sub != nextSub) {
                    break;
                }

                if (i == (steps - 1)) {
                    return true;
                }
            }
        }

        return false;
    }
};

bool common(const std::string& s) {
    Solution sn;
    return sn.repeatedSubstringPattern(s);
}

void test1() {
    std::string s = "abab";

    bool result = common(s);

    std::cout << std::boolalpha;
    std::cout << "result:" << result << std::endl;
    std::cout << "expected:" << "true" << std::endl;
}

void test2() {
    std::string s = "aba";

    bool result = common(s);

    std::cout << std::boolalpha;
    std::cout << "result:" << result << std::endl;
    std::cout << "expected:" << "false" << std::endl;
}

void test3() {
    std::string s = "abcabcabcabc";

    bool result = common(s);

    std::cout << std::boolalpha;
    std::cout << "result:" << result << std::endl;
    std::cout << "expected:" << "true" << std::endl;
}

int main() {
    // test1();
    // test2();
    test3();
    return 0;
}