class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0

        sn = sorted(nums)
        max = 1

        num = 1
        prev = sn[0]
        for value in sn[1:]:
            if value == prev:
                continue
            if value == prev + 1:
                prev = value
                num += 1
                if num > max:
                    max = num
            else:
                prev = value
                num = 1

        return max


def test1():
    s = Solution()
    nums = [100, 4, 200, 1, 3, 2]
    result = s.longestConsecutive(nums)
    print(result)

def test2():
    s = Solution()
    nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
    result = s.longestConsecutive(nums)
    print(result)

if '__name__ == __main__':
    # test1()
    test2()