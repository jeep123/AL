#include <iostream>
#include <stdexcept>
#include <string>
#include <queue>

template <typename T>
class CStack
{
public:
	CStack() { QUEUE = QUEUE1; };
	~CStack() {};
	void push(const T&);
	T pop();
	bool empty();
	enum {QUEUE1 = 0, QUEUE2} QUEUE;
private:
	std::queue<T> qu1;
	std::queue<T> qu2;
};

template <typename T> void
CStack<T>::push(const T& node)
{
	if (QUEUE == QUEUE1) 
		qu1.push(node);
	else
		qu2.push(node);
}

template <typename T> T
CStack<T>::pop()
{
	if (QUEUE == QUEUE1) {
		for (int i = 1; i < qu1.size(); i++) {
			qu2.push(qu1.front());
			qu1.pop();
		}
		T val = qu1.front();
		qu1.pop();
		QUEUE = QUEUE2;
		return val;
	} else {
		for (int i = 1; i < qu2.size(); i++) {
			qu1.push(qu2.front());
			qu2.pop();
		}
		T val = qu2.front();
		qu2.pop();
		QUEUE = QUEUE1;
		return val;
	}
}

template <typename T> bool
CStack<T>::empty()
{
	return (qu1.empty() && qu2.empty());
}

int
main(int argc, char** argv)
{
	CStack<int> sta;
	try {
		sta.push(1);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	sta.push(2);
	std::cout << sta.pop() << std::endl;
	sta.push(2);
	std::cout << sta.pop() << std::endl;
	std::cout << sta.pop() << std::endl;
	return 0;
}
