#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> results(m, std::vector<int>(n, 0));  

        results[0][0] = 1;

        for (int i = 1; i < m; i++) {
            results[i][0] = 1;
        }

        for (int i = 1; i < n; i++) {
            results[0][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                results[i][j] = results[i-1][j] + results[i][j-1];
            }
        }
        return results[m-1][n-1];
    }
};

void common(int m, int n) {
    Solution s;
    int result = s.uniquePaths(m, n);
    std::cout << m << "," << n << ", result:" << result << std::endl;
}

void test1() {
    int m = 3;
    int n = 7;
    common(m, n);
}

void test2() {
    int m = 3;
    int n = 2;
    common(m, n);
}

void test3() {
    int m = 7;
    int n = 3;
    common(m, n);
}

void test4() {
    int m = 3;
    int n = 3;
    common(m, n);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}