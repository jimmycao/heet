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
    std::string removeDuplicates(const std::string& s) {
        std::string result = "";
        std::stack<char> inStack;
        std::stack<char> outStack;

        for (auto& ch : s) {
            if (!inStack.empty()) {
                char top = inStack.top();
                if (top == ch) {
                    inStack.pop();
                } else {
                    inStack.push(ch);
                }
            } else {
                inStack.push(ch);
            }
        }

        while (!inStack.empty()) {
            char top = inStack.top();
            outStack.push(top);
            inStack.pop();
        }

        while (!outStack.empty()) {
            char top = outStack.top();
            result += top;
            outStack.pop();
        }

        return result;
    }
};

void test1() {
    Solution sn;
    std::string s = "abbaca";

    std::string result = sn.removeDuplicates(s);

    std::cout << "result:" << result << ", expected:" << "ca" << std::endl;
}

int main() {
    test1();
    // test2();
    // test3();
    return 0;
}