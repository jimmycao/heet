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
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> numStack;
        
        for (auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = numStack.top();
                numStack.pop();
                int a = numStack.top();
                numStack.pop();

                int result = 0;
                if (token == "+") {
                    result = a + b;
                } else if (token == "-") {
                    result = a - b;
                } else if (token == "*") {
                    result = a * b;
                } else if (token == "/") {
                    result = a / b;
                }

                numStack.push(result);
            } else {
                numStack.push(std::atoi(token.c_str()));
            }
        }

        return numStack.top();
    }
};

void test1() {
    Solution sn;
    std::vector<std::string> tokens {"2","1","+","3","*"};

    int result = sn.evalRPN(tokens);
    std::cout << "result:" << result << ", expected:" << 9 << std::endl;
}

void test2() {
    Solution sn;
    std::vector<std::string> tokens {"4","13","5","/","+"};

    int result = sn.evalRPN(tokens);
    std::cout << "result:" << result << ", expected:" << 6 << std::endl;
}

void test3() {
    Solution sn;
    std::vector<std::string> tokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    int result = sn.evalRPN(tokens);
    std::cout << "result:" << result << ", expected:" << 22 << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}