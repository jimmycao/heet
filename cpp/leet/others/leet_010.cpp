#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Solution {
public:
    bool isMatch(const std::string& s, const std::string& p) {
        if (p.empty() || s.empty()) {
            return false;
        }

        int i = 0;
        for (; i < s.size() &&  i < p.size(); ) {
            if (s[i] == p[i] || p[i] == '.') {
                i++;
            } else {
                break;
            }
        }

        if (i == p.size() && i == s.size()) {
            return true;
        }

        if (i == 0 && p[1] == '*') {
            std::string pLeft = p.substr(2);
            return isMatch(s, pLeft);
        }

        if ()
        if (s[i]==s[i-1] && p[i] == '*') {
            // std::string sSub = s.substr(i);
            // std::string pSub = s.substr(i);
            // return isMatch(sSub, pSub);
            return true;
        }

        if (p[i-1] == '.' && p[i] == '*') {
            return true;
        }

        return false;
    }
};

void test1() {
    std::cout << std::boolalpha;

    std::string str("aa");
    std::string p("a");

    Solution s;
    bool result = s.isMatch(str, p);
    std::cout << str << "," << p << ", result:" << result << std::endl;
}

void test2() {
    std::cout << std::boolalpha;

    std::string str("ab");
    std::string p("a.");

    Solution s;
    bool result = s.isMatch(str, p);
    std::cout << str << "," << p << ", result:" << result << std::endl;
}

void test3() {
    std::cout << std::boolalpha;
    
    std::string str("aa");
    std::string p("a*");

    Solution s;
    bool result = s.isMatch(str, p);
    std::cout << str << "," << p << ", result:" << result << std::endl;
}

void test4() {
    std::cout << std::boolalpha;

    std::string str("ab");
    std::string p(".*");

    Solution s;
    bool result = s.isMatch(str, p);
    std::cout << str << "," << p << ", result:" << result << std::endl;
}

void test5() {
    std::cout << std::boolalpha;

    std::string str("aab");
    std::string p("c*a*b");

    Solution s;
    bool result = s.isMatch(str, p);
    std::cout << str << "," << p << ", result:" << result << std::endl;
}

void test6() {
    std::cout << std::boolalpha;

    std::string str("mississippi");
    std::string p("mis*is*p*.");

    Solution s;
    bool result = s.isMatch(str, p);
    std::cout << str << "," << p << ", result:" << result << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}