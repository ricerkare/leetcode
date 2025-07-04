# Given a string s, find the longest palindromic substring in s. You may assume
# that the maximum length of s is 1000. 

# Example 1:

# Input: "babad"
# Output: "bab"
# Note: "aba" is also a valid answer.

class Solution:
    def longestPalindrome(self, s: str) -> str:
        return max([s[i:j+1] for i in range(len(s)) for j in range(i, len(s))],
                   key = lambda x: x == x[::-1])
