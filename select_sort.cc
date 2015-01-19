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
select_sort(vector<int>& vec)
{
	int size = vec.size();
	int op = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			op++;
			if (vec[j] < vec[i])
				SWAP(vec[i], vec[j]);
		}
	}
}

int
main()
{
	vector<int> vec;
	get_num(vec);
	select_sort(vec);
	print_vec(vec);
	return 0;
}
