from typing import List

class Solution1:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        使用while-loop
        """
        right = left = 0
        while right < len(nums):
            if nums[right] != 0:
                nums[left] = nums[right]
                left += 1
            right += 1

        while left < len(nums):
            nums[left] = 0
            left += 1

class Solution2:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        既然right是idx，且每个step都要+1，所以可以用for来自动+1
        使用for-loop
        """
        left = 0
        for right in range(len(nums)):
            if nums[right] != 0:
                nums[left] = nums[right]
                left += 1

        # while left < len(nums):
        #     nums[left] = 0
        #     left += 1
        for i in range(left, len(nums)):
            nums[i] = 0

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """使用idx(while-loop), 使用swap"""
        left = right = 0
        while right < len(nums):
            if nums[right] != 0:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
            right += 1

def test1():
    s = Solution()
    nums = [0, 1, 0, 3, 12]
    s.moveZeroes(nums)
    print(f"result:{nums}, expected: [1, 3, 12, 0, 0]")


def test2():
    s = Solution()
    nums = [0]
    s.moveZeroes(nums)
    print(f"result:{nums}, expected: [0]")

if __name__ == "__main__":
    test1()
    test2()