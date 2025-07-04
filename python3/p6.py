# The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
# of rows like this: (you may want to display this pattern in a fixed font for
# better legibility)

# P   A   H   N
# A P L S I I G
# Y   I   R

# And then read line by line: "PAHNAPLSIIGYIR"

# Write the code that will take a string and make this conversion given a number of rows:

# string convert(string s, int numRows);

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        topJump = 2*numRows - 2
        answer = ""

        for offset in range(topJump//2 + 1):
            for j in range(0, (len(s)//topJump + 1) * topJump + 1, topJump):
                if offset != 0 and offset != topJump//2:
                    if 0 <= j - offset < len(s):
                        answer += s[j - offset]
                    if 0 <= j + offset < len(s):
                        answer += s[j + offset]
                elif offset == 0 and 0 <= j < len(s):
                    answer += s[j]
                elif offset == topJump//2 and 0 <= j + offset < len(s):
                    answer += s[j + offset]
        
        return answer

S = Solution()
print(S.convert("PAYPALISHIRING", 3))
print(S.convert("AB", 2))
print(S.convert("ABCD", 3))
print(S.convert("ABCDE", 4))
