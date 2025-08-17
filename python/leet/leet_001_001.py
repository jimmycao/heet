class Solution:
    def twoSum(self, nums, target):
        result = []
        num2idx = {}
        for idx, num in enumerate(nums):
            if target - num in num2idx:
                result.append(idx)
                result.append(num2idx[target - num])
            else:
                num2idx[num] = idx
        return result

class Solution2:
    def twoSum(self, nums, target):
        result = []
        for i, num in enumerate(nums):
            if target - num in nums[i+1:]:
                result.append(i)

                result.append(nums.index(target-num, i+1))
        return result

def test_solution1():
    s = Solution2()
    nums = [2, 7, 11, 15]
    target = 9
    results = s.twoSum(nums, target)
    print(results)

def test_solution2():
    s = Solution2()
    nums = [2, 7, 11, 15]
    target = 9
    results = s.twoSum(nums, target)
    print(results)

if '__name__ == __main__':
    test_solution1()
    test_solution2()