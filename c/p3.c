#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char *s);

int main()
{
    {
	char *str = "asdfghjklwwpovnpoinpvowien";
	printf("%d\n", lengthOfLongestSubstring(str));
    }
    {
	char *str = "abcabcbb";
	printf("%d\n", lengthOfLongestSubstring(str));
    }
    {
	char *str = "au";
	printf("%d\n", lengthOfLongestSubstring(str));
    }

    return 0;
}

int lengthOfLongestSubstring(char * s){
    if (!s[0])
	return 0;
    if (!s[1])
	return 1;

    unsigned int max;
    int i, j, k;
    char c, d;	

    max = i = j = k = 0;
outer_loop:
    for (c = s[0]; s[i] && s[i + 1] && s[k]; c = s[i]) {
	for (d = s[++k]; d; d = s[++k]) {
	    for (j = i; j < k; j++) {
		if (s[j] == d) {
		    if (k - i > max) {
			max = k - i;
		    }
		    i = j + 1;
		    goto outer_loop;
		}
	    }
	}
	if (!d) {
	    return k - i > max ? k - i : max;
	}
    }
    return max;
}
