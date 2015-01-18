#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
#define FPATH "./num.txt"

int
get_num(vector<int>& vec)
{
	ifstream infile;
	infile.open(FPATH, ios::in);
	int num;
	while (infile >> num)
		vec.push_back(num);
	infile.close();
	return vec.size();
}

int
shell_sort(vector<int>& vec, int len)
{
	int group, i, j, temp;
	int op = 0;
	for (group = len / 2; group > 0; group /= 2) {
		for (i = group; i < len; i++) {
			temp = vec[i];
			for (j = i - group; j >= 0 && vec[j] > temp; j -= group) {
				vec[j + group] = vec[j];
				op++;
			}
			vec[j + group] = temp;
			op++;
		}
	}
	return op;
}

void
print(vector<int>& vec)
{
	vector<int>::const_iterator iter = vec.begin();
	while (iter != vec.end()) {
		cout << *iter << endl;
		iter++;
	}
}
int
main(int argc, char** argv)
{
	vector<int> vec;
	int len = get_num(vec);
	int op = shell_sort(vec, len);
	print(vec);
	cout << "operation count: " << op << endl;
	return 0;
}

