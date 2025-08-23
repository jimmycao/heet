from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        sorted_2_list = {}
        for str in strs:
            sorted_str = "".join(sorted(str))
            if sorted_str not in sorted_2_list:
                sorted_2_list[sorted_str] = []  # sorted_2_list[sorted_str] = list()
            sorted_2_list[sorted_str].append(str)

        result: List[List[str]] = []
        for s in sorted_2_list.values():
            result.append(s)
        return result


def test1():
    sn = Solution()
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    result = sn.groupAnagrams(strs)
    print(f'result: {result}, expected: [["bat"],["nat","tan"],["ate","eat","tea"]]')


def test2():
    sn = Solution()
    strs =  [""]
    result = sn.groupAnagrams(strs)
    print(f'result: {result}, expected: [[""]]')

def test3():
    sn = Solution()
    strs =  ["a"]
    result = sn.groupAnagrams(strs)
    print(f'result: {result}, expected: [["a"]]')


if __name__ == "__main__":
    test1()
    test2()
    test3()