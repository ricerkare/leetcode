#include <stdio.h>
#include <stdlib.h>

/* TODO: check for overflow. */

int32_t reverse(int32_t);

int main()
{
	int32_t foo = 1534236469;
	printf("%d\n", reverse(foo));
	return 0;
}

int32_t reverse(int32_t x)
{
	int32_t i, result = 0;

	for (i = 0; x; i++) {
		printf("%d, ", x);
		int d = x % 10;
		result = 10*result + d;
		x = (x - d) / 10;
	}
	return result;
}

