//
// Created by c00770977 on 2023/5/3.
//
#include "../../utils/tools.h"

class Solution2 {
private:
    std::vector<int> path_;
    std::vector<std::vector<int>> result_;
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        int startIdx = 1;
        backTracking(k, n, startIdx);
        return result_;
    }

    void backTracking(int k, int n, int startIdx) {
        if (path_.size() == k && std::accumulate(path_.begin(), path_.end(), 0) == n) {
            result_.push_back(path_);
            return;
        }

        for (int i = startIdx; i <= 9 && std::accumulate(path_.begin(), path_.end(), 0) < n; i++) {
            path_.push_back(i);
            backTracking(k, n, i+1);
            path_.pop_back();
        }
    }
};

// with prune
class Solution {
private:
    std::vector<int> path_;
    std::vector<std::vector<int>> result_;
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        int startIdx = 1;
        backTracking(k, n, startIdx);
        return result_;
    }

    void backTracking(int k, int n, int startIdx) {
        int sum = std::accumulate(path_.begin(), path_.end(), 0);
        if (sum > n) {
            return;
        }
        if (path_.size() == k && sum == n) {
            result_.push_back(path_);
            return;
        }

        for (int i = startIdx; i <= 9-(k-path_.size())+1; i++) {
            path_.push_back(i);
            backTracking(k, n, i+1);
            path_.pop_back();
        }
    }
};

void test1() {
    int k = 3;
    int n = 7;

    Solution sn;
    std::vector<std::vector<int>> result = sn.combinationSum3(k, n);
    print(result);
}

void test2() {
    int k = 3;
    int n = 9;

    Solution sn;
    std::vector<std::vector<int>> result = sn.combinationSum3(k, n);
    print(result);
}

void test3() {
    int k = 4;
    int n = 1;

    Solution sn;
    std::vector<std::vector<int>> result = sn.combinationSum3(k, n);
    print(result);
}

int main() {
    test1();
    std::cout << "--------------" << std::endl;
    test2();
    std::cout << "--------------" << std::endl;
    test3();
    return 0;
}