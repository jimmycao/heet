#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <iostream>

class StringTools {
public:
    template <typename T>
    static std::string ToString(const std::vector<T>& nums)
    {
        if (nums.empty()) {
            return "";
        }
        
        std::stringstream ss;
        ss << "[";
        for (int i = 0; i < nums.size() - 1; i++) {
            ss << nums[i] << ", ";
        }
        ss << nums[nums.size()-1] << "]";
        return ss.str();
    }

    template <typename T>
    static std::string ToString(const std::set<T>& nums)
    {
        if (nums.empty()) {
            return "";
        }
        
        std::stringstream ss;
        ss << "[";
        for (auto& num : nums) {
            ss << num << ", ";
        }
        ss << "]";
        return ss.str();
    }

    static std::string ToString(const std::vector<std::pair<int, int>>& nums)
    {
        std::stringstream ss;
        ss << "[";
        for (int i = 0; i < nums.size() - 1; i++) {
            ss << "(" << nums[i].first << ", " << nums[i].second << "), ";
        }
        ss << "(" << nums[nums.size()-1].first << ", " << nums[nums.size()-1].second << ")]";
        return ss.str();
    }
};
