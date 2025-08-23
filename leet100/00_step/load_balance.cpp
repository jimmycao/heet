#include <vector>
#include <iostream>
#include <algorithm>


#include "../cpp/utils/str_tools.h"

class Solution {
public:
    std::vector<int> HighestLoadServers(int serverNum, const std::vector<std::pair<int, int>>& messages) 
    {
        auto msg = messages;  // jimmy: notice!!!
        std::sort(msg.begin(), msg.end(), [](std::pair<int, int>& a, std::pair<int, int>& b) { return a.first < b.first; });
    
        std::cout << StringTools::ToString(msg) << std::endl;

        std::vector<int> server_available(serverNum, 0);
        std::vector<int> server_load(serverNum, 0);

        int next_sid = 0;
        for (auto& item : msg) {
            for (int tried_time = 0; tried_time < serverNum; tried_time++) {
                next_sid += tried_time;
                next_sid = next_sid < serverNum ? next_sid : next_sid % serverNum;
                if (server_available[next_sid] <= item.first) {
                    server_available[next_sid] += item.second;
                    server_load[next_sid] += item.second;
                    std::cout << server_available[next_sid] << ", "  << server_available[next_sid] << std::endl;
                    next_sid += 1;
                    break;
                }
            }
        }

        int max_load = 0;
        for (auto load : server_load) {
            if (load > max_load) {
                max_load = load;
            }
        }

        std::vector<int> result;
        for (int i = 0; i < serverNum; i++) {
            if (server_load[i] == max_load) {
                result.push_back(i+1);
            }
        }

        return result;
    }
};

void test1()
{
    int serverNum = 3;
    std::vector<std::pair<int, int> > messages = {{1, 15}, {2, 10}, {12, 10}, {5, 10}, {6, 10}, {30, 15}, {32, 10}};
    Solution sn;
    std::vector<int> result = sn.HighestLoadServers(serverNum, messages);
    std::string result_str = StringTools::ToString(result);
    std::cout << result_str << std::endl;   
}

int main()
{
    test1();
    return 0;
}