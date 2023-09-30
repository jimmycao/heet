#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        if (row < 1) {
            return 0;
        }

        int col = obstacleGrid[0].size();
        if (col < 1) {
            return 0;
        }

        std::vector<std::vector<int>> results(row, std::vector<int>(col, 0));
        results[0][0] = 1;

        for (int i = 0; i < row; ++i) {
            if (obstacleGrid[i][0] == 0) {
                results[i][0] = 1;
            } else {  //break;
                for (int j = i; j < row; ++j) {
                    results[j][0] = 0;
                }
                break;
            }
        }

        for (int i = 0; i < col; ++i) {
            if (obstacleGrid[0][i] == 0) {
                results[0][i] = 1;
            } else {
                for (int j = i; j < col; ++j) {
                    results[0][j] = 0;
                }
                break;
            }
        }

        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    results[i][j] = results[i-1][j] + results[i][j-1];
                } else {
                    results[i][j] = 0;  //continue;
                }

            }
        }

        return results[row-1][col-1];
    }
};

void common(std::vector<std::vector<int>>& grids) {
    Solution s;
    int result = s.uniquePathsWithObstacles(grids);

    std::for_each(grids.begin(), grids.end(), [](std::vector<int>& grid) {
        std::for_each(grid.begin(), grid.end(), [](int& i) {
            std::cout << i << " ";
        });
        std::cout << std::endl;
    });
    std::cout << "result:" << result << std::endl;
}

void test1() {
    std::vector<std::vector<int>> grids {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    common(grids);
}

void test2() {
    std::vector<std::vector<int>> grids {{0, 1}, {0, 0}};
    common(grids);
}

int main() {
    // test1();
    test2();
    return 0;
}