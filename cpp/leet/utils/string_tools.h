#include "header_tools.h"

std::string print(std::vector<int>& nums) {
    std::stringstream ss;
    for (size_t i = 0; i < nums.size()-1; ++i) {
        ss << nums[i] << " ";
    }
    ss << nums[i];
    return ss.str();
}
