class Solution:
    def reverse(self, x: int) -> int:
        if -2**31 <= x < 2**31:
            print(0)
            return int(str(x)[::-1]) if x >= 0 else -int(str(x)[1::][::-1])
        else:
            return 0

S = Solution()
print(S.reverse(1534236469))
