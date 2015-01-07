#include <stdio.h>
#include <string.h>

#define MAX 100

void
Input(char* str, char* pattern)
{
	puts("Enter the string: ");
	fgets(str, MAX, stdin);
	if (str[strlen(str)-1] = '\n')
		str[strlen(str)-1] = 0;
	puts("Enter the pattern: ");
	fgets(pattern, MAX, stdin);
	if (pattern[strlen(pattern)-1] = '\n')
		pattern[strlen(pattern)-1] = 0;
}

/* Recursion completed. */
char*
Strstr(char* str, char* pattern)
{
	if (!(*pattern))
		return NULL;
	char* s1, *s2;
	s1 = str;
	s2 = pattern;
	while (*s1 && *s2 && !(*s1 - *s2)) {
		s1++;
		s2++;
	}
	if (!(*s2))
		return str;
	if (!(*s1))
		return NULL;
	char* result = Strstr(++str, pattern);
	if (result) {
		return result;
	}
	return NULL;
}

int
main(int argc, char** argv)
{
	char str[MAX], pattern[MAX];
	memset(str, 0, sizeof(str));
	memset(pattern, 0, sizeof(pattern));
	Input(str, pattern);
	char* res = NULL;
	res = Strstr(str, pattern);
	if (res) {
		puts("===============");
		puts(res);
	}
	return 0;
}
