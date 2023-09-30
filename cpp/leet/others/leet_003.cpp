#include <vector>
#include <unordered_map>
#include <iostream>
#include <iterator>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.empty()) {
            return 0;
        }

        int maxLen = 1;
        std::string maxSubStr{s[0]};

        for (int i = 0; i < s.size()-1; ++i) {
            std::string sub{s[i]};
            for (int j = i+1; j <= s.size()-1; ++j) {
                if (sub.find(s[j]) == std::string::npos) {
                    sub.push_back(s[j]);
                } else {
                    break;
                }
            }

            if (sub.size() > maxLen) {
                maxLen = sub.size();
                maxSubStr = sub;
            }
        }

        std::cout << "maxSubStr:" << maxSubStr << std::endl;
        return maxLen;
    }
};


int main() {
    // std::string s1 {"abcabcbb"};
    
    // std::string s2("bbbbb");
    // std::string s3 {"pwwkew"};
    // std::string s4 {"abcade"};
    // std::string s5{""};
    std::string s6{" "};

    Solution s;
    int result1 = s.lengthOfLongestSubstring(s6);
    std::cout << "result1:" << result1 << std::endl;

    return 0;
}