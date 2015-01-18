#include <iostream>
#include <string>
#include <stack>

using namespace std;

template <typename T>
class CQueue
{
public:
	CQueue(){};
	~CQueue(){};

	void push(const T& node);
	T pop();
	bool empty();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T> bool
CQueue<T>::empty()
{
	return (stack1.empty() && stack2.empty());
}

template <typename T> void
CQueue<T>::push(const T& node)
{
	stack1.push(node);
}

template <typename T> T
CQueue<T>::pop()
{
	while (!stack1.empty()) {
		stack2.push(stack1.top());
		stack1.pop();
	}
	T value = stack2.top();
	stack2.pop();
	return value;
}

int
main(int argc, char** argv)
{
	CQueue<int> qu;
	int i;
	while (cin >> i)
		qu.push(i);
	cout << qu.pop() << std::endl;
	qu.push(90000);
	while (!qu.empty())
		cout << qu.pop() << " " << endl;
	return 0;
}
