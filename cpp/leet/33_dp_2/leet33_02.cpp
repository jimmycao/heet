#include "../utils/header_tools.h"
#include "../utils/print_tools.h"

/*
 * 最有子结构  optimal substructure
 */
class Solution1 {  // 递归法
public:
    int cut(vector<int>& prices, int len) {
        if (len == 0) {
            return 0;
        }

        int R = INT_MIN;
        for (size_t i = 1; i <= len; ++i) {  // i从1开始切，每切一次，len = len - i
            R = std::max(R, prices[i-1] + cut(prices, len -i ));
            // max(r, R_1 + R_len-1, R_2 + R_len-2, ..., R_len-1 + R_1)
        }
        return R;
    }
};

class Solution2 {  // 递归 + memo 法
public:
    int cut(vector<int>& prices, int len) {
        vector<int> memo(len+1, -1);
        return cutWithMemo(prices, len, memo);
    }

    int cutWithMemo(vector<int>& prices, int len, vector<int>& memoOut) {
        if (memoOut[len] >= 0) {  // 如见已经有记录值，就直接使用
            return memoOut[len];
        }

        int R = -1;

        if (len == 0) {
            return 0;
        } else {
            for (size_t i = 1; i <= len; i++) {
                R = std::max(R,  prices[i - 1] + cutWithMemo(prices, len - i, memoOut));
            }
        }

        memoOut[len] = R; // 把每个长度的最大价值都记录下来
//        std::cout << "len:" << len << ", R:" << R << std::endl;
        return R;
    }
};

class Solution {  // 自底向上 + DP + 记忆
public:
    int cut(vector<int>& prices, int len) {
        vector<int> memo(len+1, 0);

        for (size_t i = 1; i <= len; ++i) {
            int R = -1;
            for (size_t j = 1; j <= i; j++) {
                R = std::max(R, prices[j-1] + memo[i-j]);
            }
            memo[i] = R;
            std::cout << "i:" << i << ", R:" << R << std::endl;
        }
        return memo[len];
    }
};

void test1() {
    vector<int> prices {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int len = 10;

    Solution sn;
    int result = sn.cut(prices, len);
    std::cout << "result:" << result << std::endl;
}

int main() {
    test1();
    return 0;
}