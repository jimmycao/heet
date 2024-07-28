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

if '__name__ == __main__':
    s = Solution()
    nums = [2, 7, 11, 15]
    target = 9
    results = s.twoSum(nums, target)
    print(results)