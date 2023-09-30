#include <climits>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

void print(std::vector<int>& nums) {
    std::for_each(nums.begin(), nums.end(), [](int i) {std::cout << i << " ";});
    std::cout << std::endl;
}

void print(std::vector<std::vector<int>>& nums) {
    std::for_each(nums.begin(), nums.end(), [](std::vector<int> num) {
        std::for_each(num.begin(), num.end(), [](int i) {std::cout << i << " ";});
        std::cout << std::endl;
    });
}

class TwoVecLess {
public:
    bool operator()(const std::vector<int>& a, const std::vector<int>& b) const {
        if (a.size() !=  b.size()) {
            return a.size() < b.size();
        }

        std::vector<int> aa(a);
        std::vector<int> bb(b);
        std::sort(aa.begin(), aa.end());
        std::sort(bb.begin(), bb.end());

        // print(aa);
        // print(bb);

        for (int i = 0; i < aa.size(); ++i) {
            if (aa[i] < bb[i]) {
                return true;
            }

            if (aa[i] > bb[i]) {
                return false;
            }
        }
        return false;
    }
};

void test1() {
    std::set<std::vector<int>, TwoVecLess> vecSet;
    std::vector<std::vector<int>> vecs {{0,1,2}, {0,3,4}, {1,0,2}, {1,2,4}, {2,0,1}, {2,1,4}, {3,0,4}, {4,0,3}, {4,1,2}};
    for (auto vec : vecs) {
        vecSet.insert(vec);
    }
    
    std::cout << "----------" << std::endl;
    for (auto item : vecSet) {
        print(item);
    }
}

int main() {
    test1();
    return 0;
}