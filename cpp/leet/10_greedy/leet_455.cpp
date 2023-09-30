#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void print(const std::vector<int>& g);

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        if (g.size() == 0 || s.size() == 0) {
            return 0;
        }

        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (result < g.size() && s[i] >= g[result]) {
                result++;
            } 
        }
        // print(g);
        // print(s);

        return result;
    }
};

void print(const std::vector<int>& g) {
    std::for_each(g.begin(), g.end(), [](int i) { std::cout <<  i << " "; });
    std::cout << std::endl;
}

void common(std::vector<int>& g, std::vector<int>& s) {
    Solution sn;
    int result = sn.findContentChildren(g, s);
    std::cout << "result:" << result << std::endl;
}

void test1() {
    std::vector<int> g{2, 1, 3};
    std::vector<int> s{1, 1};
    common(g, s);
}

void test2() {
    std::vector<int> g{1, 2};
    std::vector<int> s{1, 2, 3};
    common(g, s);
}

int main() {
    // test1();
    test2();
    return 0;
}