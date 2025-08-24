#include <vector>
#include <iostream>

class Solution {
public:
    int trap(std::vector<int>& height) 
    {   
        int result = 0;

        int left = 0;
        int right = height.size() - 1;
        int leftMaxH = 0;
        int rightMaxH = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMaxH) {
                    leftMaxH = height[left];
                } else {
                    result += leftMaxH - height[left]; 
                }
                left++;
            } else {
                if (height[right] >= rightMaxH) {
                    rightMaxH = height[right];
                } else {
                    result += rightMaxH - height[right]; 
                }
                right--;
            }
        }

        return result;
    }
};

void test1() 
{
    Solution sn;
    std::vector<int> height {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = sn.trap(height);
    std::cout << "result: " << result << ", expected: 6" << std::endl; 
}

void test2() 
{
    Solution sn;
    std::vector<int> height {4, 2, 0, 3, 2, 5};
    int result = sn.trap(height);
    std::cout << "result: " << result << ", expected: 9" << std::endl; 
}

int main()
{
    test1();
    test2();
    return 0;
}
