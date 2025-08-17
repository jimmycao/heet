#include "str_tools.h"

#include <iostream>

void test1()
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::string result = StringTools::ToString(nums);
    std::cout << result << std::endl;
}

int main()
{
    test1();
    return 0;
}