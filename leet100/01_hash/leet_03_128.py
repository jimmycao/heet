from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        lst = sorted(list(set(nums)))
        if len(lst) == 1:
            return 1

        longest = 1

        count = 1
        prev = lst[0]  # 用一个变量来记录上一个值，且不断滑动
        for value in lst[1:]:
            if value == prev + 1:
                prev = value
                count += 1
                if count > longest:
                    longest = count
            else:
                prev = value
                count = 1

        return longest


def test1():
    sn = Solution()
    nums = [100, 4, 200, 1, 3, 2]
    result = sn.longestConsecutive(nums)
    print(f"reuslt: {result}, expected: 4")

def test2():
    sn = Solution()
    nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
    result = sn.longestConsecutive(nums)
    print(f"reuslt: {result}, expected: 9")

def test3():
    sn = Solution()
    nums = [9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6]
    result = sn.longestConsecutive(nums)
    print(f"reuslt: {result}, expected: 7")

if __name__ == "__main__":
    test1()
    test2()
    test3()