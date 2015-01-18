#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>::iterator ITER;

#define EXCHANGE(A, B) do {\
	if (A == B) break; \
	A ^= B; \
	B ^= A; \
	A ^= B; \
} while (0) 

ITER
partition(vector<int>& vec, ITER begin, ITER end)
{
	ITER left = begin - 1;
	ITER right = begin;
	int temp = *end;
	while (right <= end)
	{
		if (*right <= temp)
		{
			left++;
			EXCHANGE(*left, *right);
		}
		right++;
	}
	return left;
}

void
quick_sort(vector<int>& vec, ITER begin, ITER end) // this end is not the vec.end(), bu vec.end() - 1
{
	if (begin >= end)
		return;
	ITER pivort = partition(vec, begin, end);
	quick_sort(vec, begin, pivort - 1);
	quick_sort(vec, pivort + 1, end);
}

void
get_num(vector<int>& vec)
{
	cout << "the numbers: ";
	int num; 
	cin >> num;
	int n;
	while (num != 0)
	{
		cin >> n;
		vec.push_back(n);
		num--;
	}
}

void
print_vec(vector<int>& vec)
{
	int i = 0;
	cout << "The sorted : ";
	while (i != vec.size())
	{
		cout << vec[i] << " ";
		i++;
	}
}

int
main()
{
	vector<int> vec;
	get_num(vec);
	quick_sort(vec, vec.begin(), vec.end() - 1);
	print_vec(vec);
	return 0;
}
