class Solution:
    def maxArea(self, height: list[int]) -> int:
        left = 0
        right = len(height) - 1

        result = 0
        while left < right:
            area = min(height[left], height[right]) * (right - left)
            result = max(result, area)
            if height[left] <= height[right]:
                left += 1
            else:
                right -= 1

        return result


def test1():
    s = Solution()
    nums = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    result = s.maxArea(nums)
    expected = 49
    print(f"result:{result}, expected:{expected}")

def test2():
    s = Solution()
    nums = [1, 1]
    result = s.maxArea(nums)
    expected = 1
    print(f"result:{result}, expected:{expected}")

if '__name__ == __main__':
    test1()
    test2()