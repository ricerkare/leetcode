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




/*
  Given a string, find the length of the longest substring without repeating
  characters. 
  
  Example 1:
  
  Input: "abcabcbb"
  Output: 3 
  Explanation: The answer is "abc", with the length of 3. 
*/
/*
  int lengthOfLongestSubstring(char * s){
  if (!s[0])
  return 0;
  if (!s[1])
  return 1;
		
  unsigned int max;
  int i, j, k;
  char c, d;	

  max = i = j = k = 0;
  /* In the following set of nested loops:
  - we start with c = s[i]
  - let k = i + 1, d = s[i + 1]. Check if s[i] == d
  - if not, let k = i + 2, d = s[k], check if s[j] == d for j = i, 
  j = i + 1
  - if neither, let k = i + 3, d = s[k]. Check if s[j] == d for
  j = i, j = i + 1, j = i + 2
  et cetera.

  If it fails at any point then record k - j - 1 as the new maximum
  and start again at i = k+1.
		   
  s[i+1] is undefined only if s[i] == '\0', so the condition of the
  outermost loop is still valid in this case (due to short-
  circuiting). */
	
/* /* /* /* /*outer_loop:
   for (c = s[0]; s[i] && s[i + 1] && s[k]; c = s[i]) {
   for (d = s[++k]; d; d = s[++k]) {
   for (j = i; j < k; j++) {
   printf("%d %d %d\n", i, j, k);

   if (s[j] == d) {
   /* Now we know that s[i]s[i+1]...s[k-1] is unique
   (i.e. it doesn't contain duplicate characters)
   by induction, but s[i]s[i+1]...s[k] is not 
   since s[j] == s[k] (and i <= j <= k), so the new
   maximum length is ((k-1) - i) + 1 = k - i. */
/*					if (k - i > max) {
					max = k - i;
					printf("max = %d\n", max);
					}
					/* At this point, s[j] == s[k] so now we can start i
					immediately after j, as every substring that both
					starts before j and is not already checked will
					either contain s[j] and s[k] (not unique) or be
					shorter than s[j]...s[k]. */

/* Finally, we can leave k where it is because we 
   know that s[i]s[i+1]...s[k-1] is unique, hence
   s[j+1]...s[k] is also unique. */
/*
  i = j + 1;
  goto outer_loop;
  }
  }
  }
  }
  return max;
  }
*/
