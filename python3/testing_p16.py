# I'm trying out twoSumClosest before tackling threeSumClosest. 

from typing import List

class Solution:
    def twoSumClosest(self, nums: List[int], target: int) -> int:
        size = len(nums)
        nums.sort()
        i = 0
        j = size - 1
        closest_sum = None
        i_prime = i
        j_prime = j
        print(nums)
        while i != j:
            cur_sum = nums[i] + nums[j]
            if cur_sum == target:
                return cur_sum
            elif closest_sum == None:
                closest_sum = cur_sum
            elif abs(cur_sum - target) <= abs(closest_sum - target):
                closest_sum = cur_sum
                i_prime = i
                j_prime = j
            if cur_sum - target > 0:
                j -= 1
            else:
                i += 1

        print(i_prime, j_prime)
        return closest_sum


inputs = [[[-1, 2, 1, -4], 1],
          [[3, 1, 5, 2], 200]]

for i in inputs:
    solution = Solution()
    print(solution.twoSumClosest(i[0], i[1]))
