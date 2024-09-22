class Solution1:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        slow = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[slow] = nums[i]
                slow += 1

        for j in range(slow, len(nums)):
            nums[j] = 0

        return nums

class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        left = right = 0
        size = len(nums)
        while right < size:
            if nums[right] != 0:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
            right += 1
        return nums

def test1():
    s = Solution()
    nums = [0, 1, 0, 3, 12]
    result = s.moveZeroes(nums)
    expected = [1, 3, 12, 0, 0]
    print(f"result:{result}, expected:{expected}")


def test2():
    s = Solution()
    nums = [0]
    result = s.moveZeroes(nums)
    expected = [0]
    print(f"result:{result}, expected:{expected}")

if '__name__ == __main__':
    test1()
    test2()