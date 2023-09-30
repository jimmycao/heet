#include <climits>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(const std::string& s, const std::string& t) {
        std::vector<int> sVec(26, 0);
        std::vector<int> tVec(26, 0);

        for (auto ch : s) {
            sVec[ch-'a']++;
        }

        for (auto ch : t) {
            tVec[ch-'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (sVec[i] != tVec[i]) {
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