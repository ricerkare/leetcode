class Solution:
    def myAtoi(self, s: str) -> int:
        try:
            foo = s.strip()
            i = 0
            if i < len(foo) and (foo[i] == '-' or foo[i] == '+'):
                i += 1
            while  i < len(foo) and '0' <= foo[i] <= '9':
                i += 1
            foo = foo[:i]
            foo = int(foo)
            if -2**31 <= foo < 2**31:
                return foo
            elif foo < -2**31:
                return -2**31
            else:
                return 2**31
        except:
            return 0

S = Solution()
print(S.myAtoi("\t\n    \t +142534214342qwerqer"))
print(S.myAtoi("42"))
