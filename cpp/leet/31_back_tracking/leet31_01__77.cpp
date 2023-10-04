#include "../utils/print_tools.h"

class Solution2 {
private:
    std::vector<int> path_;
    std::vector<std::vector<int>> result_;

public:
    std::vector<std::vector<int>> combine(int n, int k) {
        backTracking(n, k, 1);
        return result_;
    }

    void backTracking(int n, int k, int startIdx) {
        if (path_.size() == k) {
            result_.push_back(path_);
            return;
        }

        for (int i = startIdx; i <= n; ++i) {
            path_.push_back(i);
            backTracking(n, k, i+1);
            path_.pop_back();
        }
    }
};

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        backTracking(n, k, 1);
        return result_;
    }

    void backTracking(int n, int k, int startIdx) {
        if (path_.size() == k) {
            result_.push_back(path_);
            return;
        }

        for (int i = startIdx; i <= n-(k-path_.size())+1; ++i) {  // 剪枝
//        for (size_t i = startIdx; i <= n; ++i) {
            path_.push_back(i);
            backTracking(n, k, i+1);
            path_.pop_back();
        }
    }

private:
    std::vector<int> path_;
    std::vector<std::vector<int>> result_;
};

void test1() {
    int n = 4;
    int k = 2;

    Solution sn;
    std::vector<std::vector<int>> result = sn.combine(n, k);
    print(result);
}

void test2() {
    int n = 1;
    int k = 1;

    Solution sn;
    std::vector<std::vector<int>> result = sn.combine(n, k);
    print(result);
}

int main() {
    test1();
    std::cout << "---" << std::endl;
    test2();
    return 0;
}