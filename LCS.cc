#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M_N_1 0
#define M_1 1
#define N_1 2

#define MAX 1000

static int c[MAX+1][MAX+1], b[MAX+1][MAX+1];

void
LCS(char* A, char* B)
{
	int len1 = strlen(A);
	int len2 = strlen(B);
	if (len1 <= 0 || len2 <= 0)
		return;
	int m = 0, n = 0;

	for (m = 1; m <= len1; m++) {  // from 1 to len1, size is len1
		for (n = 1; n <= len2; n++) {
			if (A[m-1] == B[n-1]) {
				c[m][n] = c[m-1][n-1] + 1;
				b[m][n] = M_N_1;
			} else {
				if (c[m-1][n] > c[m][n-1]) {
					c[m][n] = c[m-1][n];
					b[m][n] = M_1;
				} else {
					c[m][n] = c[m][n-1];
					b[m][n] = N_1;
				}
			}
		}
	}

	printf("MAX length: %d\n", c[m-1][n-1]);

}

void
print_path(int m, int n, char* A)
{
	if (m*n == 0) return;
	if (b[m][n] == M_N_1)
	{
		print_path(m-1, n-1, A);
		putchar(A[m-1]);
	}
	else if (b[m][n] == M_1)
		print_path(m-1, n, A);
	else
		print_path(m, n-1, A);
}

int
main(int argc, char** argv)
{
	if (argc < 3) {
		printf("two strings\n");
		return -1;
	}

	memset(c, 0, MAX*MAX);
	memset(b, 0, MAX*MAX);
	char* A = argv[1];
	char* B = argv[2];
	LCS(A, B);
	print_path(strlen(A), strlen(B), A);
	putchar('\n');
	return 0;
}
