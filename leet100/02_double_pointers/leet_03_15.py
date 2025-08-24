from typing import List

# 会超时
class Solution1:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)

        result: List[List[int]] = []
        for i in range(len(nums)):
            if nums[i] > 0:  # 提前退出
                break
            for j in range(i+1, len(nums)):
                diff = 0 - (nums[i] + nums[j])
                if diff in nums[j+1:]:
                    sorted_tmp = [nums[i], nums[j], diff]
                    # sorted_tmp = sorted(sorted_tmp)  # 由于在一开始就sorted过了，所以这里没必要
                    if sorted_tmp not in result:
                        result.append([nums[i], nums[j], diff])
        return result

# 会超时
class Solution2:
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

class Solution3:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []

        nums.sort()
        for first in range(len(nums)):
            if first > 0 and nums[first] == nums[first-1]:
                continue

            third = len(nums) - 1
            for second in range(first+1, len(nums)):
                if second > first + 1 and nums[second] == nums[second-1]:
                    continue

                while second < third and nums[first] + nums[second] + nums[third] > 0:
                    third -= 1

                if second == third:
                    break

                if nums[first] + nums[second] + nums[third] == 0:
                    result.append([nums[first], nums[second], nums[third]])
        return result

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        results = []
        nums.sort()

        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                continue

            left = i + 1
            right = len(nums) - 1
            while left < right:
                # 跳过重复的left
                # if left > i+1 and nums[left] == nums[left-1]:
                #     left += 1
                #     continue

                sum = nums[i] + nums[left] + nums[right]
                if sum == 0:
                    results.append([nums[i], nums[left], nums[right]])
                    left += 1

                    # 跳过重复的left
                    while left < right and nums[left] == nums[left-1]:
                        left += 1
                elif sum < 0:
                    left += 1
                else:
                    right -= 1
        return results

def test1():
    s = Solution()
    nums = [-1, 0, 1, 2, -1, -4]
    result = s.threeSum(nums)
    print(f"result:{result}, expected: [[-1, -1, 2], [-1, 0, 1]]")

def test2():
    s = Solution()
    nums = [0, 1, 1]
    result = s.threeSum(nums)
    print(f"result:{result}, expected: []")

def test3():
    s = Solution()
    nums = [0,0,0]
    result = s.threeSum(nums)
    print(f"result:{result}, expected: [[0,0,0]]")

if __name__ == "__main__":
    test1()
    test2()
    test3()