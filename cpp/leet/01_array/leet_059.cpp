#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void print(const std::vector<std::vector<int>>& g);

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        int startx = 0;
        int starty = 0;

        int offset = 1;
        int num = 1;

        while (offset <= n / 2) {
            int x = startx;
            int y = starty;

            for (; y < n-offset; ++y) {
                matrix[x][y] = num++;
            }
            for (; x < n-offset; ++x) {
                matrix[x][y] = num++;
            } 
        
            for (; y > starty; --y) {
                matrix[x][y] = num++;
            } 
            for (; x > startx; --x) {
                matrix[x][y] = num++;
            } 

            offset++;
            startx++;
            starty++;
        }

        if (n % 2 == 1) {
            matrix[startx][starty] = n * n;
        }

        return matrix;
    }
};

void print(const std::vector<std::vector<int>>& g) {
    std::for_each(g.begin(), g.end(), [](std::vector<int> v) { 
        std::for_each(v.begin(), v.end(), [](int i) { std::cout << i << " "; });
        std::cout << std::endl;
     });
}

void common(int n) {
    Solution sn;
    std::vector<std::vector<int>> result = sn.generateMatrix(n);
    std::cout << "result:" << std::endl;
    print(result);
}

void test1() {
    int n = 3;
    common(n);

    std::cout << n << ", expected:" << std::endl;
    std::vector<std::vector<int>> expected {{1,2,3}, {8,9,4}, {7,6,5}};
    print(expected);
}

void test2() {
    int n = 1;
    common(n);

    std::cout << n << ", expected:" << std::endl;
    std::vector<std::vector<int>> expected {{1}};
    print(expected);
}

void test3() {
    int n = 4;
    common(n);

    std::cout << n << ", expected:" << std::endl;
    std::vector<std::vector<int>> expected {{1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7}};
    print(expected);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}