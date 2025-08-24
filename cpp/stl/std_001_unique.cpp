#include <algorithm>
#include <vector>

#include "../utils/str_tools.h"

// sort & unique & erase
void test1()
{
    std::vector<int> orig {1, 2, 1, 2, 3};
    std::sort(orig.begin(), orig.end());

    auto new_end = std::unique(orig.begin(), orig.end());
    orig.erase(new_end, orig.end());
    
    std::cout << "orig: " << StringTools::ToString(orig) << ", expected: [1, 2, 3]" << std::endl;
}


int main()
{
    test1();
    return 0;
}