#include <iostream>
#include <vector>

#define SWAP(A, B) do { \
	if (A == B) break; \
	A ^= B; \
	B ^= A; \
	A ^= B; \
} while(0)

using namespace std;

bool sorted = true;

void
get_num(vector<int>& vec)
{
	cout << "Enter the number of the list: ";
	int count, num;
	cin >> count;
	cout << "Enter the number list:\n";
	while (count--)
	{
		cin >> num;
		vec.push_back(num);
	}
}

void
print_vec(vector<int>& vec)
{
	vector<int>::const_iterator iter;
	for (iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

void
bubble_sort_quick(vector<int>& vec)
{
	int op = 0;
	int num = vec.size();
	for (int i = 0; i < num; i++)
	{
		sorted = true;
		for (int j = 1; j < num - i; j++)
		{
			op++;
			if (vec[j - 1] > vec[j])
			{
				SWAP(vec[j - 1], vec[j]);
				sorted = false;
			}
		}
		if (sorted) break;
	}
	cout << "quick operations is: " << op << endl;
}

void
bubble_sort(vector<int>& vec)
{
	int op = 0;
	int num = vec.size();
	for (int i = 0; i < num; i++)
	{
		for (int j = 1; j < num - i; j++)
		{
			op++;
			if (vec[j - 1] > vec[j])
			{
				SWAP(vec[j - 1], vec[j]);
			}
		}
	}
	cout << "slow operations is: " << op << endl;
}

int
main()
{
	vector<int> vec, vecq;
	get_num(vec);
	vecq = vec;
	bubble_sort(vec);
	bubble_sort_quick(vecq);
	print_vec(vec);
	print_vec(vecq);
	return 0;
}
