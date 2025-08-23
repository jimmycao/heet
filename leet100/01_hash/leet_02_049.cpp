#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#include "../../cpp/utils/str_tools.h"


class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) 
    {
        std::map<std::string, std::vector<std::string>> sorted_2_strs;
        for (auto& str : strs) {
            auto str_copy = str;
            std::sort(str_copy.begin(), str_copy.end());
            sorted_2_strs[str_copy].push_back(str);
        }

        std::vector<std::vector<std::string>> results;
        for (auto& item : sorted_2_strs) {
            results.push_back(item.second);
        }
        return results;
    }
};

void test1()
{
    Solution sn;
    std::vector<std::string> strs {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> results = sn.groupAnagrams(strs);
    std::cout << "[['bat'],['nat','tan'],['ate','eat','tea']]" << std::endl;
    for (auto& vec : results) {
        std::cout << StringTools::ToString(vec) << std::endl;
    }
}

int main()
{
    test1();
    return 0;
}