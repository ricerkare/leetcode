"""
Given n non-negative integers a_1, a_2, ..., a_n , where each represents a point
at coordinate (i, a_i). n vertical lines are drawn such that the two endpoints
of line i is at (i, a_i) and (i, 0). Find two lines, which together with x-axis
forms a container, such that the container contains the most water. 

Note: You may not slant the container and n is at least 2.
"""

import math

class Solution:
    def maxArea(self, height) -> int:
        if (len(height)) == 2:
            return min(height)
        maximumWater = 0
        prevWidth = 0
        prevHeight = 0
        H = list(enumerate(height))
        # First, sort H by heights.
        SH = sorted(H, key=lambda x: x[1])
        
        # For a, b in SH[0], find the maximum width from a that holds
        # water. Then set new maximumWater to longest width times the smaller
        # height, which is a since SH is sorted. Do the same procedure for each
        # successive SH[i], except don't search inside a minWidth of a in which
        # heights are guaranteed to hold less water than  maximumWater.

        for a, b in SH:
            if b == 0:
                continue
            # We want to check if newHeight * newWidth > prevHeight * prevWidth,
            # i.e. we only need to check when newWidth > prevHeight/newHeight *
            # prevWidth. (For SH[0], minWidth = 0.)
            minWidth = int(math.floor(prevHeight * prevWidth / b))
            upperRangeMin = min(len(H), max(a, a + minWidth - 1))
            upperRange = H[-1 : upperRangeMin : -1]
            print("upperRange =", upperRange)
            lowerRangeMax = max(0, min(a, a - minWidth + 1))
            lowerRange = H[ : lowerRangeMax]
            print("lowerRange =", lowerRange)

            widthFound = False
            for R in [upperRange, lowerRange]:
                for c, d in R:
                    if d >= b:
                        if maximumWater < abs(a-c) * b:
                            maximumWater = abs(a-c) * b
                            prevWidth = abs(a-c)
                            widthFound = True
                            # Only the smaller height is counted (in this case,
                            # b), so we do not need to check for narrower
                            # widths. Hence, break.
                            break
            if not widthFound:
                prevWidth = 0
            prevHeight = b
        return maximumWater
            
S = Solution()
h = [1, 2, 4, 3]
print(S.maxArea(h))
h = [2,3,4,5,18,17,6]
print(S.maxArea(h))

h = \
[166,63,82,92,144,186,192,68,101,179,50,170,141,31,149,131,180,94,168,142,91,137,159,184,89,135,101,21,70,191,136,37,7,18,81,103,4,26,171,106,5,173,28,99,4,129,30,185,23,198,127,67,88,39,51,129,126,104,150,196,48,38,185,7,56,19,110,12,45,33,70,50,7,98,149,163,179,131,100,3,82,180,70,170,171,73,51,97,130,153,45,130,191,31,137,199,2,199,11,47]
print(S.maxArea(h))

"""def maxArea(height):
    maximum = 0
    sortedHeights = sorted(enumerate(height), key=lambda x: x[1])
    for i in range(len(sortedHeights)):
        newMaxWidth = max([abs(sortedHeights[i][0] - h[0]) \
                           for h in sortedHeights[i + 1:]])
        newMax = newMaxWidth * sortedHeigs[i][1]
    if newMax > maximum:
        maximum = newMax
    return maximum
class Solution:
    def maxArea(self, height: List[int]) -> int:
        maximum = 0
        L = list(enumerate(height))
        for (a, b) in L:
            for (c, d) in L[a+1:]:
                if (c - a) * min(b, d) > maximum:
                    maximum = (c - a) * min(b, d)
        return maximum

"""
