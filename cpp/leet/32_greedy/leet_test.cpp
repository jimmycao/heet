#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>


void print(const std::vector<int>& g) {
    std::for_each(g.begin(), g.end(), [](int i) { std::cout <<  i << " "; });
    std::cout << std::endl;
}

void common(std::vector<int>& g) {
    print(g);
    std::sort(g.begin(), g.end());
    print(g);

}

void test1() {
    std::vector<int> g{2, 1, 3};
    common(g);
}

int main() {
    test1();
    return 0;
}