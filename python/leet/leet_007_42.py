from typing import List

class Solution:
    def trap(self, heights: List[int]) -> int:
        result = 0
        left, right = 0, len(heights) - 1

        leftMax = rightMax = 0

        while left < right:
            leftMax = max(leftMax, heights[left])
            rightMax = max(rightMax, heights[right])
            if heights[left] < heights[right]:
                result += (leftMax - heights[left])
                left += 1
            else:
                result += (rightMax - heights[right])
                right -= 1

        return result


def test1():
    s = Solution()
    heights = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    result = s.trap(heights)
    expected = 6
    print(f"result:{result}, expected:{expected}")

if '__name__ == __main__':
    test1()