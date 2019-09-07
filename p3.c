/*
  Given a string, find the length of the longest substring without repeating
  characters. 
  
  Example 1:
  
  Input: "abcabcbb"
  Output: 3 
  Explanation: The answer is "abc", with the length of 3. 
*/

int lengthOfLongestSubstring(char * s){
    unsigned int max;
	int i, j, k;
    char c, d;	

	max = i = j = k = 0;
	/* s[j+1] is undefined only if s[j] == '\0', so the condition is still valid
	   in this case. */
    for (c = s[0]; s[i] && s[i + 1]; c = *(s += i)) {
        for (d = s[++k]; d; d = s[++k]) {
			for (j = i; j < k; j++) {
				if (s[j] == d) {
					if (j - i > max) {
						max = k - j;
					}
					/* Now we know that s[j]s[j+1]...s[k] is 
					/* At this point, s[j] == s[k] so now we can start
					   i immediately after j, as every substring that 
					   both starts before j and is not already checked 
					   will either contain s[j] and s[k] (not unique) or
					   be shorter than s[j...k] */
					   
					break;
				}
			}
		}
    }
}

int lengthOfLongestSubstring(char *s)
{
	unsigned int max;
	int i;
	char c, d;

	for (c = s[0]; c; c = ++s) {
		for (i = 0, d = s[++i]; c != d && d; d = s[++i]);
		if (i > max) {
			max = i;
		}
	}

	return max;
}
			
/*
int lengthOfLongestSubstring(char *s)
{
	unsigned int max;
	/* char_indices[i] gives indices where 'a' + i occurs in s. */
	unsigned int *char_indices['z' - 'a'  + 1][strlen(s)];
	char c;

	for (c = *s; c; c = *++s) {
		char_indices
*/
