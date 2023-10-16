#include "../../utils/print_tools.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sMap(26, 0);
        for (auto it = s.begin(); it != s.end(); ++it) {
            sMap[*it - 'a']++;
        }

        for (auto it = t.begin(); it != t.end(); ++it) {
            sMap[*it - 'a']--;
        }

        for (auto item : sMap) {
            if (item != 0) {
                return false;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t) {
            return true;
        } else {
            return false;
        }
    }
};

void test1() {
    string s = "anagram";
    string t = "nagaram";

    Solution sn;
    bool result = sn.isAnagram(s, t);
    std::cout << std::boolalpha;
    std::cout << "result:" << result;
    std::cout << ", expected:true" << std::endl;
}

void test2() {
    string s = "rat";
    string t = "car";

    Solution sn;
    bool result = sn.isAnagram(s, t);
    std::cout << std::boolalpha;
    std::cout << "result:" << result;
    std::cout << ", expected:false" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}