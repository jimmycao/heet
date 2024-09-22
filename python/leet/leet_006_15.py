from typing import List

class Solution1:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        results = set()
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                to_find = 0 - (nums[i] + nums[j])
                for k in range(j+1, len(nums)):
                    if nums[k] == to_find:
                        item = [nums[i], nums[j], nums[k]]
                        results.add(tuple(sorted(item)))  # 借助tuple，set才能去重
                        break

        return [list(t) for t in results]   # 把tuple转成list


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []

        nums.sort()
        size = len(nums)
        for first in range(size):
            if first > 0 and nums[first] == nums[first-1]:
                continue

            third = size - 1
            target = -nums[first]

            for second in range(first+1, size):
                if second > first + 1 and nums[second] == nums[second-1]:
                    continue

                while second < third and nums[second] + nums[third] > target:
                    third -= 1

                if second == third:
                    break

                if nums[second] + nums[third] == target:
                    result.append([nums[first], nums[second], nums[third]])
        return result

def test1():
    s = Solution()
    nums = [-1, 0, 1, 2, -1, -4]
    result = s.threeSum(nums)
    expected = [[-1, -1, 2], [-1, 0, 1]]
    print(f"result:{result}, expected:{expected}")

if '__name__ == __main__':
    test1()