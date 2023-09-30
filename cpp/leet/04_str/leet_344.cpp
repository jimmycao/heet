#include <climits>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>

void print(std::vector<char>& chs) {
    std::for_each(chs.begin(), chs.end(), [](char i) {std::cout << i << " ";});
    std::cout << std::endl;
}

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        char tmp;
        for (int i = 0, j = s.size()-1; i < j; i++, j--) {
            // tmp = s[i];
            // s[i] = s[j];
            // s[j] = tmp;
            std::swap(s[i], s[j]);
        }
    }
};

class Solution2 {
public:
    void reverseString(std::vector<char>& s) {
        std::reverse(s.begin(), s.end());
    }
};

void common(std::vector<char>& s) {
    Solution sn;
    sn.reverseString(s);
}

void test1() {
    std::vector<char> s{'h','e','l','l','o'};

    common(s);

    std::cout << "results:" << std::endl;
    print(s);
    std::cout << "expected:" << "o, l, l, e, h" << std::endl;
}

void test2() {
    std::vector<char> s{'H', 'a', 'n', 'n', 'a', 'h'};

    common(s);

    std::cout << "results:" << std::endl;
    print(s);
    std::cout << "expected:" << "h,a, n,n,a,H" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}