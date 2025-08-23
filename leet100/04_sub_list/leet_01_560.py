from typing import List

# 暴力法
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        result = 0

        for i in range(len(nums)):
            sum = 0
            # i只是为了记录边界；j从i开始
            for j in range(i, len(nums)):
                sum += nums[j]
                if sum == k:
                    result += 1
        return result

def test1():
    nums = [1, 1, 1]
    k = 2

    sn = Solution()
    result = sn.subarraySum(nums, k)
    print(f"result:{result}, expected:2")

def test2():
    nums = [1, 2, 3]
    k = 3

    sn = Solution()
    result = sn.subarraySum(nums, k)
    print(f"result:{result}, expected:2")

def test3():
    nums = [1, 2, 1, 2, 1]
    k = 3

    sn = Solution()
    result = sn.subarraySum(nums, k)
    print(f"result:{result}, expected:4")

def test4():
    nums = [1, -1, 0]
    k = 0

    sn = Solution()
    result = sn.subarraySum(nums, k)
    print(f"result:{result}, expected:3")

if __name__ == "__main__":
    test1()
    test2()
    test3()
    test4()