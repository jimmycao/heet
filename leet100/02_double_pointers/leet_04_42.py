from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        result = 0

        left = 0
        right = len(height) - 1
        leftMaxHeight = rightMaxHeight = 0
        while left < right:
            if height[left] < height[right]:
                if height[left] >= leftMaxHeight:
                    leftMaxHeight = height[left]
                else:
                    result += leftMaxHeight - height[left]
                left += 1
            else:
                if height[right] >= rightMaxHeight:
                    rightMaxHeight = height[right]
                else:
                    result += rightMaxHeight - height[right]
                right -= 1
        return result

def test1():
    s = Solution()
    heights = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    result = s.trap(heights)
    print(f"result:{result}, expected: 6")

def test2():
    s = Solution()
    heights = [4, 2, 0, 3, 2, 5]
    result = s.trap(heights)
    print(f"result:{result}, expected: 9")

if __name__ == "__main__":
    test1()
    test2()