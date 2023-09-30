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
#include <queue>
#include <unordered_map>

class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> charStack;

        char tmp;

        for (auto ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                charStack.push(ch);
            }

            if (ch == ')' || ch == ']' || ch == '}') {
                if (charStack.empty()) {
                    return false;
                }
                tmp = charStack.top();
                if (ch == ')' && tmp != '(') {
                    return false;
                }     

                if (ch == ']' && tmp != '[') {
                    return false;
                }

                if (ch == '}' && tmp != '{') {
                    return false;
                }

                charStack.pop();
            }
        }

        if (charStack.empty()) {
            return true;
        } 
        return false;
    }
};

void test1() {
    Solution sn;
    std::string s = "()";

    bool result = sn.isValid(s);

    std::cout << std::boolalpha;
    std::cout << "result:" << result << ", expected:" << true << std::endl;
}

void test2() {
    Solution sn;
    std::string s = "()[]{}";

    bool result = sn.isValid(s);

    std::cout << std::boolalpha;
    std::cout << "result:" << result << ", expected:" << true << std::endl;
}

void test3() {
    Solution sn;
    std::string s = "(]";

    bool result = sn.isValid(s);

    std::cout << std::boolalpha;
    std::cout << "result:" << result << ", expected:" << false << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}