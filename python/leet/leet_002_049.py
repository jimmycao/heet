class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        orig2strs = {}
        for str in strs:
            ss = ''.join(sorted(str))
            if ss not in orig2strs:
                orig2strs[ss] = []
            orig2strs[ss].append(str)

        results = []
        # for value in orig2strs.values():
        #     results.append(value)
        for key, value in orig2strs.items():
            results.append(value)

        return results

if '__name__ == __main__':
    s = Solution()
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    results = s.groupAnagrams(strs)
    print(results)