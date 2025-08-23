class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0

        left = 0

        max_set = {s[left]}
        max_len = 1

        right = left + 1
        while right < len(s):
            if s[right] not in max_set:
                max_set.add(s[right])
                if len(max_set) > max_len:
                    max_len = len(max_set)
                right += 1
            else:
                max_set.clear()
                left += 1
                max_set.add(s[left])
                right = left + 1

        return max_len

def test1():
    s = Solution()
    ss = "abcabcbb"
    result = s.lengthOfLongestSubstring(ss)
    expected = 3
    print(f"result:{result}, expected:{expected}")

def test2():
    s = Solution()
    ss = ""
    result = s.lengthOfLongestSubstring(ss)
    expected = 0
    print(f"result:{result}, expected:{expected}")

def test3():
    s = Solution()
    ss = "aab"
    result = s.lengthOfLongestSubstring(ss)
    expected = 2
    print(f"result:{result}, expected:{expected}")

def test4():
    s = Solution()
    ss = "dvdf"
    result = s.lengthOfLongestSubstring(ss)
    expected = 3
    print(f"result:{result}, expected:{expected}")

if '__name__ == __main__':
    test1()
    test2()
    test3()
    test4()