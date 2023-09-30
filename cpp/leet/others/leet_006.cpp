#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <iterator>
#include <string>
#include <string_view>
#include <cassert>

class Solution {
public:
    std::string padding(const std::string& s, int numRows) {
        std::string result;

        int totalSteps = 0;
        for (int i = 0; i < s.size(); ) {
            int currStep = totalSteps % (numRows-1);
            if (currStep == 0) {
                int j = 0;
                for (; j < numRows; j++) {
                    if (i < s.size()) {
                        result.push_back(s[i++]);
                    } else {
                        result.push_back('#');
                    }
                }
            } else {
                int prefix = numRows - currStep -1;
                for (int j = 0; j < prefix; j++) {
                    result.push_back('#');
                }
                result.push_back(s[i++]);
                for (int j = 0; j < currStep; j++) {
                    result.push_back('#');
                }
            }
            totalSteps++;
        }
        return result;
    }

    std::vector<std::string> split(const std::string& str, int numRows) {
        std::vector<std::string> results;

        for (int i = 0; i < str.size();) {
            std::string tmp;
            for (int j = 0; j < numRows && i < str.size(); ++j) {
                tmp.push_back(str[i++]);
            }
            results.push_back(tmp);
        }

        return results;
     }

    std::vector<std::string> tranpose(const std::vector<std::string> splits, int numRows) {
        std::vector<std::string> results;
        for (int i = 0; i < numRows; ++i) {
            std::string tmp;
            for (int j = 0; j < splits.size(); ++j) {
                tmp.push_back(splits[j][i]);
            }
            results.push_back(tmp);
        }
        return results;
    }

    std::string removePadding(const std::vector<std::string>& trans) {
        std::string result;
        for (auto& str : trans) {
            for (int i = 0; i < str.size(); ++i) {
                if (str.at(i) != '#') {
                    result.push_back(str.at(i));
                }
            }
        }
        
        return result;
    }

    std::string convert(const std::string& s, int numRows) {
        assert(s.size()>=1 && s.size() <= 1000);
        assert(numRows >=1 && numRows <= 1000);

        if (numRows == 1) {
            return s;
        }

        std::string padStr = padding(s, numRows);

        // std::cout << "padStr" << ":" << padStr << std::endl;

        std::vector<std::string> splits = split(padStr, numRows);

        std::vector<std::string> trans = tranpose(splits, numRows);

        // for (auto& item : trans) {
        //     std::cout << item << std::endl;
        // }

        std::string result = removePadding(trans);

        return result;
    }
};

void test1() {
    std::string str{"PAYPALISHIRING"};
    // std::string str{"123456789ABCDE"};
    int row = 3;

    Solution s;
    std::string result = s.convert(str, row);
    std::cout << result << std::endl;
}

void test2() {
    std::string str{"PAYPALISHIRING"};
    // std::string str{"123456789ABCDE"};
    int row = 4;

    Solution s;
    std::string result = s.convert(str, row);
    std::cout << result << std::endl;
}

void test3() {
    // std::string str{"PAYPALISHIRING"};
    std::string str{"123456789ABCDE"};
    int row = 2;

    Solution s;
    std::string result = s.convert(str, row);
    std::cout << result << std::endl;
}

int main() {
    // test1();
    // test2();
    // test3();

    return 0;
}