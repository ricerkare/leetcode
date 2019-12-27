#include <regex.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int isMatch(char *s, char *p);

int main()
{
	char s[] = "aaaaa";
	char p[] = "aaa*";
	printf("%d\n", isMatch(s, p));

	return 0;
}

int isMatch(char *str, char *pattern){
	regex_t		compiled;
	int			foo;
	size_t		nmatch = 1;
	regmatch_t	pmatch[nmatch];

	foo = regcomp(&compiled, pattern, 0);
	if (foo) {
		return false;
	}
	foo = regexec(&compiled, str, nmatch, pmatch, 0);

	size_t match_size = pmatch[0].rm_eo - pmatch[0].rm_so;
	if (match_size != strlen(str)) {
		return false;
	}

	char match_str[match_size+1];
	memcpy(match_str, str + (pmatch[0].rm_so), match_size);
	match_str[match_size] = '\0';
		
	regfree(&compiled);
		
	if (strlen(match_str) == strlen(str)) {
		return (bool) !foo;
	}

	return 0;
}

