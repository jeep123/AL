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

/* The standard sunday match */
int
SundayMatch(char* pSrc, int nSrcSize, char* pSubSrc, int nSubSrcSize)
{
	int skip[256];
	for (int i = 0; i < 256; i++)
		skip[i] = nSubSrcSize + 1;
	for (int i = 0; i < nSubSrcSize; i++)
		skip[pSubSrc[i]] = nSubSrcSize - i;
	int nPos = 0;
	while (nPos <= nSrcSize - nSubSrcSize) {
		int j = nSubSrcSize - 1;
		while (j >= 0 && pSrc[nPos + j] == pSubSrc[j])
			j--;
		if (j < 0)
			break;
		nPos += skip[pSrc[nPos + nSubSrcSize]];
	}
	return nPos;
}

static size_t
FindLocation(char* byte, char* str, size_t size)
{
	size_t i = 0;
	while (i < size) {
		if (*(str - i) == *byte)
			return (i + 1);
		i++;
	}
	return (i + 1);
}

/* sunday */
char*
Sunday(char* str, char* pattern)
{
	size_t psize = strlen(pattern);
	size_t ssize = strlen(str);
	size_t scount = 0;
	if (ssize < psize)
		return NULL;
	char* s1 = str + psize - 1, *s2 = pattern + psize - 1;
	while (*(s1)) {
		size_t count = 0;
		char* bs1 = s1, *bs2 = s2;
		while ((psize - count) && !(*bs1 - *bs2)) {
			bs1--;
			bs2--;
			count++;
		}
		if (count == psize)
			return (bs1 + 1);
		if (!(*(s1 + 1)))
			return NULL;
		size_t step = FindLocation(s1 + 1, s2, psize);
		s1 += step;
		if ((scount += step) > ssize)
			return NULL;
	}
	return NULL;
}


/* loop method */
char*
Str_str(char* str, char* pattern)
{
	size_t position = 0;
	char* s1 = str, *s2 = pattern;
	char* ptr = NULL;
	while (*s1) {
		ptr = s1;
		while (*s1 && *s2 && !(*s1 - *s2)) {
			s1++;
			s2++;
		}
		if (!(*s2))
			return (s1 - strlen(pattern));
		if (!(*s1))
			return NULL;
		s1 = ++ptr;
		s2 = pattern;
		position++;
	}
	return NULL;
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
//	res = Strstr(str, pattern);
//	res = Str_str(str, pattern);
//	res = Sunday(str, pattern);
	if (res) {
		puts("===============");
		puts(res);
	}
	int nPos = SundayMatch(str, strlen(str), pattern, strlen(pattern));
	if (nPos) {
		puts("++++++++++++++++++");
		puts(&str[nPos]);
	}
	return 0;
}
