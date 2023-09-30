#include "header_tools.h"

void print(std::vector<int>& nums) {
    for_each(nums.begin(), nums.end(), [](int i) {
        std::cout << i << " ";
    });
    std::cout << std::endl;
}

void print(std::vector<std::vector<int>>& vecs) {
    for_each(vecs.begin(), vecs.end(), [](std::vector<int> nums) {
        for_each(nums.begin(), nums.end(), [](int i) {
            std::cout << i << " ";
        });
        std::cout << std::endl;
    });
}
