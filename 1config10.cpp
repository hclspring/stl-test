#include <iostream>
#include <cstddef> // for size_t
using namespace std;

class alloc {};

template <class T, class Alloc = alloc, size_t BufSize = 0>
class deque {
public:
	deque() { cout << "deque" << endl; }
};

// 根据前一个参数值T，设定下一个参数Sequence的默认值为deque<T>
template <class T, class Sequence = deque<T> >
class stack {
public:
	stack() { cout << "stack" << endl; }
private:
	Sequence a; // 如果有此行，则先调用deque的构造函数
	Sequence* b; // 此行不影响构造stack时是否调用deque的构造函数
};

int main() {
	stack<int> x;
}

