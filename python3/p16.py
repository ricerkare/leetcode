# Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

# Return the sum of the three integers.

# You may assume that each input would have exactly one solution.

# Example 1:

# Input: nums = [-1,2,1,-4], target = 1
# Output: 2
# Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

# Example 2:

# Input: nums = [0,0,0], target = 1
# Output: 0
# Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

# Constraints:

#     3 <= nums.length <= 500
#     -1000 <= nums[i] <= 1000
#     -104 <= target <= 104

from typing import List

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        size = len(nums)
        nums.sort()
        closest_sum = nums[0] + nums[1] + nums[size - 1]
        for i in range(size - 2):
            j = i + 1
            k = size - 1
            ith = nums[i]
            while j != k:
                cur_sum = ith + nums[j] + nums[k]
                if cur_sum == target:
                    return cur_sum
                elif closest_sum == None:
                    closest_sum = cur_sum
                elif abs(cur_sum - target) < abs(closest_sum - target):
                    closest_sum = cur_sum
                    j_prime = j
                    k_prime = k
                if cur_sum - target > 0:
                    k -= 1
                else:
                    j += 1
        return closest_sum


inputs = [[[-1, 2, 1, -4], 1],
          [[0,0,0], 1],
          [[3, 1, 5, 2, 192], 200]]

for i in inputs:
    solution = Solution()
    print(solution.threeSumClosest(i[0], i[1]))
