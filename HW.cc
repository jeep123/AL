#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX 1000
static int c[MAX][MAX];
static int cc[MAX][MAX];
static char t[MAX][MAX];
static int longest = 1;
static int begin = 0;

void
init()
{
	memset(c, -1, MAX*MAX);
	memset(t, 0, MAX*MAX);
	memset(cc, 0, MAX*MAX);
}

void
init_LW(char* ptr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cc[i][i] = 1;
		if ((i != size - 1) && (ptr[i] == ptr[i + 1]))
		{
			longest = 2;
			begin = i;
			cc[i][i + 1] = 1;
		}
	}
}

void
LW1(char* ptr, int size)
{
	if (size < 3)
		return;
	for (int len = 3; len <= size; len++)
	{
		for (int i = 0; i <= size - 2; i++)
		{
			if ((ptr[i] == ptr[i + len - 1]) && cc[i + 1][i + len - 2])
			{
				cc[i][i + len - 1] = 1;
				longest = len;
				begin = i;
			}
		}
	}
}


int
LW(char* array, int begin, int end)
{
	if (begin > end)
		return 0;
	int i = begin, j = end;
	while (i < j && array[i] == array[j])
	{
		i++;
		j--;
	}
	if (i >= j)
	{
		c[begin][end] = end - begin + 1;
		t[begin][end] = 0;
		return (end - begin + 1);
	}
	int first, second;
	if ((first = c[begin + 1][end]) >= 0)
	{
	}
	else	
		first = LW(array, begin + 1, end);
	if ((second = c[begin][end - 1]) >= 0)
	{
	}
	else
		second = LW(array, begin, end - 1);
	if (first > second)
	{
		t[begin][end] = -1;
		return first;
	}
	else
	{
		t[begin][end] = 1;
		return second;
	}
}

void
print_trace(char* ptr, int begin, int end)
{
	if (t[begin][end] == -1)
		print_trace(ptr, begin + 1, end);
	else if (t[begin][end] == 1)
		print_trace(ptr, begin, end - 1);
	else
		while (begin <= end)
		{
			cout << ptr[begin];
			begin++;
		}
}

void
print_longest(char* ptr)
{
	cout << "longest: " << longest << endl;
	for (int i = 0; i < longest; i++)
		cout << ptr[begin + i];
	cout << endl;
}

int
main(int argc, char** argv)
{
	init();
	if (argc < 2)
	{
		cout << "enter the string" << endl;
		return -1;
	}
	char* ptr = argv[1];
	int size = strlen(ptr);
//	int num = LW(ptr, 0, size - 1);
	init_LW(ptr, size);
	LW1(ptr, size);
//	cout << "++++++ " << num << endl;
//	print_trace(ptr, 0, size - 1);

	print_longest(ptr);
//	cout << endl;
	return 0;
}
