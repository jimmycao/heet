#include <vector>
#include <iostream>

class Solution {
public:
    int maxArea(std::vector<int>& height) 
    {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int area = std::min(height[left], height[right]) * (right - left);
            max_area = std::max(area, max_area);
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};

void test1()
{
    Solution sn;
    std::vector<int> height {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = sn.maxArea(height);
    std::cout << "result: " << result << ", expected: 49" << std::endl;
}

void test2()
{
    Solution sn;
    std::vector<int> height {1, 1};
    int result = sn.maxArea(height);
    std::cout << "result: " << result << ", expected: 1" << std::endl;
}

int main()
{
    test1();
    test2();
    return 0;
}