from typing import List

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        result = []

        sorted_p = sorted(p)

        start = 0
        while start <= len(s) - len(p):
            tmp = sorted(s[start:start+len(p)])
            if sorted_p == tmp:
                result.append(start)
            start += 1

        return result

def test1():
    s = Solution()
    ss = "cbaebabacd"
    p = "abc"
    result = s.findAnagrams(ss, p)
    expected = [0,6]
    print(f"result:{result}, expected:{expected}")

def test2():
    sn = Solution()
    s = "abab"
    p = "ab"
    result = sn.findAnagrams(s, p)
    expected = [0,1,2]
    print(f"result:{result}, expected:{expected}")

if '__name__ == __main__':
    test1()
    test2()