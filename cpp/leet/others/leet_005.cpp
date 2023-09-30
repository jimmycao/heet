#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <iterator>
#include <string>

class Solution {
public:
    bool isPalindrome(const std::string& s) {
        // std::string s2(s);
        // std::reverse(s2.begin(), s2.end());
        // if (s2 == s) {
        //     return true;
        // } else {
        //     return false;
        // }
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            } 
        }
         
        return true;
    }

    std::string longestPalindrome(std::string& s) {
        if (s.empty()) {
            return std::move(std::string(""));
        }
        if (s.size() == 1) {
            return s;
        }

        int size = s.size();

        int max = 0;
        std::string result{""};

        for (int len = 1; len <= size; ++len) {
            for (int start = 0; start < size-1; ++start) {
                if (start + len > size) {
                    break;
                }

                std::string sub = s.substr(start, len);
                if (sub.size() > max && isPalindrome(sub)) {
                    max = sub.size();
                    result = sub;
                }
            }
        }

        return std::move(result);
    }


    std::string longestPalindrome2(std::string& s) {
        if (s.empty()) {
            return std::move(std::string(""));
        }
        if (s.size() == 1) {
            return s;
        }
        for (int len = s.size(); len > 0; len--) {
            for (int i = 0; i + len <= s.size(); ++i) {
                std::string sub = s.substr(i, len);
                if (isPalindrome(sub)) {
                    return sub;
                }
            }
        }
        return std::move(std::string(""));
    }
};

void test_isPalindrome() {
    std::string str{"haha"};
    Solution s;
    std::cout << s.isPalindrome(str) << std::endl;
}

void test1() {
    std::string str{"babad"};

    Solution s;
    std::string sub = s.longestPalindrome(str);
    std::cout << sub << std::endl;
}

void test2() {
    std::string str{"cbbd"};

    Solution s;
    std::string sub = s.longestPalindrome(str);
    std::cout << sub << std::endl;
}

void test3() {
    std::string str{"c"};

    Solution s;
    std::string sub = s.longestPalindrome(str);
    std::cout << sub << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    // test_isPalindrome();
    return 0;
}