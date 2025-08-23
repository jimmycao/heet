from typing import List

# 双指针，暴力法
class Solution1:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = []

        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    result.append(i)
                    result.append(j)
                    return result

# 单指针，求差法，向前查
class Solution2:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = []

        for idx, value in enumerate(nums):
            if target - value in nums[idx+1:]:
                result.append(idx)
                result.append(nums.index(target-value, idx+1))
                return result

# 单指针，求差法，向后查
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = []
        num2idx = {}

        for idx, num in enumerate(nums):
            if target - num in num2idx:
                result.append(idx)
                result.append(num2idx[target-num])
                return result
            else:
                num2idx[num] = idx


def test1():
    sn = Solution()
    nums = [2, 7, 11, 15]
    target = 9
    result = sn.twoSum(nums , target)
    print(f"result:{result}, expected:[0, 1]")

def test2():
    sn = Solution()
    nums = [3, 2, 4]
    target = 6
    result = sn.twoSum(nums, target)
    print(f"result:{result}, expected:[1, 2]")

if __name__ == "__main__":
    test1()
    test2()