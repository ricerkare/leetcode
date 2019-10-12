#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int);

int main()
{
	

	return 0;
}

bool isPalindrome(int x)
{
	if (x < 0) {
		return false;
	}
	int y = 0, tmp = x;
	while (tmp) {
		int d = tmp % 10;
		y = 10*y + d;
		tmp /= 10;
	}
	return x == y;
}

