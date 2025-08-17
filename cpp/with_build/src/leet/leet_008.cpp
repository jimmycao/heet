#include <climits>

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Solution {
public:
    int myAtoi(const std::string& s) {
        if (s.empty()) {
            return 0;
        } 

        int start = -1;
        int end = -1;
        int factor = 1;

        long long value = -1;

        //mark start and factor
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                //mark start and factor
                if (start == -1) {
                    start = i;
                }

                if (i != 0 && s[i-1] == '-') {
                    factor = -1; 
                }
                break;
            }
        }

        if (start == -1) {
            return 0;
        }

        //check all previous char
        for (int i = 0; i < start-1; i++) {
            if (s[i] != ' ') {
                return 0;
            }
        }

        if (start >= 1) {
            if (s[start-1] != ' ' && s[start-1] != '+' && s[start-1] != '-') {
                return 0;
            }
        } 
       
        for (; start == '0'; start++);

        //mark end
        for (end = start; s[end] >='0' && s[end] <= '9'; end++);

        int len = end - start;
        std::string sub = s.substr(start, len);

        std::stringstream ss;
        ss << sub;
        ss >> value;

        value *= factor;

        if (value > INT_MAX) {
            value = INT_MAX;
        }

        if (value < INT_MIN) {
            value = INT_MIN;
        }

        return value;
    }
};

void test1() {
    std::string line("42");
    Solution s;
    int result = s.myAtoi(line);
    std::cout << "test1 result:" << result << std::endl;
}

void test2() {
    std::string line("   -42");
    Solution s;
    int result = s.myAtoi(line);
    std::cout << "test2 result:" << result << std::endl;
}

void test3() {
    std::string line("4193 with words");
    Solution s;
    int result = s.myAtoi(line);
    std::cout << "test3 result:" << result << std::endl;
}

void test4() {
    std::string line(" 0032");
    Solution s;
    int result = s.myAtoi(line);
    std::cout << "test4 result:" << result << std::endl;
}

void test5() {
    std::string line("words and 987");
    Solution s;
    int result = s.myAtoi(line);
    std::cout << "test5 result:" << result << std::endl;
}

void test6() {
    std::string line("");
    Solution s;
    int result = s.myAtoi(line);
    std::cout << "test6 result:" << result << std::endl;
}

void test7() {
    std::string line("+");
    Solution s;
    int result = s.myAtoi(line);
    std::cout << "test7 result:" << result << std::endl;
}

void test8() {
    std::string line("+1");
    Solution s;
    int result = s.myAtoi(line);
    std::cout << "test8 result:" << result << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    return 0;
}