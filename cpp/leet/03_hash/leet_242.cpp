#include <climits>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <unordered_map>

void print(const std::map<char, int>& ch2count) {
    for (auto it : ch2count) {
        std::cout << it.first << ":" << it.second << std::endl;
    }
}

class Solution {
public:
    bool isAnagram(const std::string& s, const std::string& t) {
        std::map<char, int> ch2countS;
        std::map<char, int> ch2countT;

        for (auto ch : s) {
            if(ch2countS[ch]) {
                ch2countS[ch]++;
            } else {
                ch2countS[ch] = 1;
            }
        }

        // print(ch2countS);

        for (auto ch : t) {
            if (ch2countT[ch]) {
                ch2countT[ch]++;
            } else {
                ch2countT[ch] = 1;
            }
        }

        // print(ch2countT);

        if (ch2countS.size() != ch2countT.size()) {
            return false;
        }

        auto itS = ch2countS.begin();
        auto itT = ch2countT.begin();
        for (; itS != ch2countS.end() && itT != ch2countT.end(); ++itS, ++itT) {
            if (itS->first != itT->first || itS->second != itT->second) {
                return false;
            }
        }

        return true;
    }
};

bool common(const std::string& s, const std::string& t) {
    Solution sn;
    return sn.isAnagram(s, t);
}

void test1() {
    std::string s("anagram");
    std::string t("nagaram");

    bool result = common(s, t);

    std::cout << std::boolalpha;
    std::cout << "result:" << result << std::endl;
    std::cout << "expected:" << true << std::endl;
}

void test2() {
    std::string s("rat");
    std::string t("car");

    bool result = common(s, t);

    std::cout << std::boolalpha;
    std::cout << "result:" << result << std::endl;
    std::cout << "expected:" << false << std::endl;
}

void test3() {
    std::string s("aa");
    std::string t("a");

    bool result = common(s, t);

    std::cout << std::boolalpha;
    std::cout << "result:" << result << std::endl;
    std::cout << "expected:" << false << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}