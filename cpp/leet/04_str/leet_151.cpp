#include <climits>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <unordered_map>

class Solution {
public:
    std::string reverseWords(const std::string& s) {
        std::stack<std::string> strStack;

        size_t end = 0;
        size_t start = s.find_first_not_of(' ');
        for (; start != std::string::npos; ) {
            end = s.find_first_of(' ', start);
            std::string word;
            if (end != std::string::npos) {
                word = s.substr(start, end-start);
            } else {
                word = s.substr(start);
            }

            strStack.push(word);

            start = s.find_first_not_of(' ', end);
        }

        std::string result = "";
        while (!strStack.empty()) {
            result += strStack.top();
            if (strStack.size() != 1) {
                result += " ";
            }
            strStack.pop();
        }
        return result;
    }   
};

std::string common(std::string s) {
    Solution sn;
    return sn.reverseWords(s);
}

void test1() {
    std::string s = "the sky is blue";

    std::string result = common(s);

    std::cout << "result:" << result << std::endl;
    std::cout << "expected:" << "blue is sky the" << std::endl;
}

void test2() {
    std::string s = "  hello world  ";

    std::string result = common(s);

    std::cout << "result:" << result << std::endl;
    std::cout << "expected:" << "world hello" << std::endl;
}

void test3() {
    std::string s = "a good   example";

    std::string result = common(s);

    std::cout << "result:" << result << std::endl;
    std::cout << "expected:" << "example good a" << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}