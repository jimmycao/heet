//
// Created by c00770977 on 2023/5/3.
//
#include "../../utils/tools.h"

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string& digits) {
        if (digits.empty()) {
            return {};
        }

        std::vector<std::vector<char>> charArrays(digits.size());
        for (int i = 0; i < digits.size(); ++i) {
            charArrays.push_back(myDict_[digits[i]]);
        }

        for (size_t i = 0; i < charArrays.size(); ++i) {
            for (auto& ch : charArrays[i]) {

            }
        }


    }

private:
    std::map<char, std::vector<char>> myDict_ { {'2', {'a', 'b', 'c'}},
                                                {'3', {'d', 'e', 'f'}},
                                                {'4', {'g', 'h', 'i'}},
                                                {'5', {'j', 'k', 'l'}},
                                                {'6', {'m', 'n', 'o'}},
                                                {'7', {'p', 'q', 'r', 's'}},
                                                {'8', {'t', 'u', 'v'}},
                                                {'9', {'w', 'x', 'y', 'z'}} };
    std::vector<std::string> result_;
    std::string str_;
};

void test1() {
    std::string digits = "23";

    Solution sn;
    std::vector<std::string> result = sn.letterCombinations(digits);
    for_each(result.begin(), result.end(), [](std::string str) {
        std::cout << str << " ";
    });
    std::cout << std::endl;

    std::cout << "expected:";
    std::vector<std::string> expected {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    for_each(expected.begin(), expected.end(), [](std::string str) {
        std::cout << str << " ";
    });
    std::cout << std::endl;
}

int main() {
    test1();
    return 0;
}