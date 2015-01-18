#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;
#define MAX 1000
#define MAX_NUM(x, y) (x > y)? x : y
#define HAS 1
#define NOHAS 0

static int W[MAX];
static int V[MAX];
static int f[MAX][MAX];
static int t[MAX][MAX];
static vector<int> vec;

int
largest_value(int weight, int id)
{
	memset(f, 0, MAX*MAX);
	memset(t, 0, MAX*MAX);

	for (int m = 1; m <= weight; m++)
	{
		for (int n = 1; n <= id; n++)
		{
			int first, second = 0;
			if (m - W[n] > 0)
				second = f[m-W[n]][n-1] + V[n];
			first = f[m][n-1];
			//f[m][n] = MAX_NUM(first, second);
			if (first >= second)
				f[m][n] = first;
			else
			{
				f[m][n] = second;
				t[m][n] = HAS;
			}
			
		}
	}
	return f[weight][id];
}

int
get_num()
{
	int count;
	cout << "The Num: ";
	cin >> count;
	cout << "Read object weight value:" << endl;
	for (int i = 0; i < count; i++)
	{
		cin >> W[i+1] >> V[i+1];
	}
	return count;
}

void
print_path()
{
	vector<int>::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << "Object: " << *iter << " Weight: "
			 << W[*iter] << " Value: " << V[*iter] << endl;
	}
}

void
print_trace(int weight, int id)
{
	if (weight == 0 || id == 0)
		return;
	if (t[weight][id])
	{
		cout << "Object: " << id << " Weight: "
			 << W[id] << " Value: " << V[id] << endl;
		//cout << "==== " << weight-W[id] << "  " << id-1 << endl;
		cout << f[weight][id] << endl;
		print_trace(weight-W[id], id-1);
	}
	else
		print_trace(weight, id-1);
}

int
main()
{
	int weight = 20;
	int count = get_num();
	int value = largest_value(weight, count);
	cout << "**** " << value << endl;
	print_trace(weight, count);
	return 0;
}
