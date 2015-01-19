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
insert_sort(vector<int>& vec)
{
	int size = vec.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (vec[j] < vec[j - 1])
				SWAP(vec[j], vec[j - 1]);
		}
	}
}

int
main()
{
	vector<int> vec;
	get_num(vec);
	insert_sort(vec);
	print_vec(vec);
	return 0;
}
