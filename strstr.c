#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

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

/*
 * Name: kmp
 * Description: kmp method for string match.
 */
 int
 kmp(const char* text, int text_len, const char* find, int find_len)
 {
 	if (text == NULL || find == NULL)
		return -1;
//	int find_len = strlen(find);
//	int text_len = strlen(text);
	if (text_len < find_len)
		return -1;
	int map[find_len];
	memset(map, 0, find_len*sizeof(int));
	// initial the kmp base array: map
	map[0] = 0;
	int i;
	for (i = 1; i < find_len; i++)
	{
		if (map[i - 1] == 0)
		{
			if (find[i] == find[0])
				map[i] = 1;
			else
				map[i] = 0;
		}
		else
		{
			if (find[i] == find[map[i - 1]])
				map[i] = map[i - 1] + 1;
			else if (find[i] == find[0])
				map[i] = 1;
			else
				map[i] = 0;
		}
	}

	int j = 0;
	i = 0;
	while (i < text_len && j < find_len)
	{
		if (text[i] == find[j])
		{
			i++;
			j++;
			continue;
		}
		if (j == 0)
		{
			i++;
			continue;
		}
		j = map[j - 1];
	}

	if (j == find_len)
		return (i - j);
	return -1;


/*	while (i < text_len)
	{
		while (i < text_len && j != find_len && text[i] == find[j])
		{
			j++;
			i++;
		}
		if (j == find_len)
			return (i - j);
		if (j == 0)
		{
			i++;
			continue;
		}
		j = map[j - 1];
	}
	return -1;
*/
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
//	int nPos = SundayMatch(str, strlen(str), pattern, strlen(pattern));
	int nPos = kmp(str, strlen(str), pattern, strlen(pattern));
	if (nPos != -1) {
		puts("++++++++++++++++++");
		puts(&str[nPos]);
	}
	return 0;
}
