#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <unordered_map>


int main() {
    std::vector<int> nums {2,5,5,11};
    int target = 10;

    std::unordered_map<int, int> num2pos;

    for (int i = 0; i < nums.size(); ++i) {
        num2pos[nums[i]] = i;
    }

    std::for_each(num2pos.begin(), num2pos.end(), [](auto it) { std::cout << it.first << ", " << it.second << std::endl;});
}