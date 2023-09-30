#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(int x) {
        std::stringstream ss;
        ss << x;
        std::string input;
        ss >> input;

        std::string origin = input;

        std::reverse(input.begin(), input.end());

        if (input == origin) {
            return true;
        } else {
            return false;
        }
    }
};

void test1() {
    int input = 121;

    Solution s;
    bool result = s.isPalindrome(input);
    std::cout << input <<", result:" << result << std::endl;
}

void test2() {
    int input = -121;
    
    Solution s;
    bool result = s.isPalindrome(input);
    std::cout << input << ", result:" << result << std::endl;
}

void test3() {
    int input = 10;
    
    Solution s;
    bool result = s.isPalindrome(input);
    std::cout << input << ", result:" << result << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}