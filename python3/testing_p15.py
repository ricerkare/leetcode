from typing import List

class Solution:
    def twoSum(self, nums: List[int]) -> List[List[int]]:
        size = len(nums)
        nums.sort()
        pairs = []
        i = 0
        j = size - 1
        while i != j:
            print(i, j)
            total = nums[i] + nums[j]
            if total == 0:
                pairs.append([nums[i], nums[j]])
                i += 1
            elif total > 0:
                j -= 1
            else:
                i += 1
        return pairs

solution = Solution()
foo = solution.twoSum([-7,-1,-13,2,13,2,12,3,-11,3,7,-15,2,-9,-13,-13,11,-10,5,-13,2,-12,0,-8,8,-1,4,10,-13,-5,-6,-4,9,-12,5,8,5,3,-4,9,13,10,10,-8,-14,4,-6,5,10,-15,-1,-3,10,-15,-4,3,-1,-15,-10,-6,-13,-9,5,11,-6,-13,-4,14,-3,8,1,-4,-5,-12,3,-11,7,13,9,2,13,-7,6,0,-15,-13,-11,-8,9,-14,1,11,-7,13,0,-6,-15,11,-6,-2,4,2,9,-15,5,-11,-11,-11,-13,5,7,7,5,-10,-7,6,-7,-11,13,9,-10,-9])
print(foo)
