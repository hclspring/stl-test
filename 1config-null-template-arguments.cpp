#include <iostream>
#include <cstddef>
using namespace std;

class alloc {};

template <class T, class Alloc = alloc, size_t BufSize = 0>
class deque {
public:
	deque() { cout << "deque "; }
};

template <class T, class Sequence>
class stack;

template <class T, class Sequence>
bool operator==(const stack<T, Sequence>&,
		const stack<T, Sequence>&);

template <class T, class Sequence>
bool operator<(const stack<T, Sequence>&,
		const stack<T, Sequence>&);

template <class T, class Sequence = deque<T> >
class stack {
	// 写成这样是可以的
	friend bool operator== <T> (const stack<T>&, const stack<T>&);
	friend bool operator< <T> (const stack<T>&, const stack<T>&);
	// 写成这样也是可以的
	friend bool operator== <T> (const stack&, const stack&);
	friend bool operator< <T> (const stack&, const stack&);
	// 写成这样也是可以的
	friend bool operator== <> (const stack&, const stack&);
	friend bool operator< <> (const stack&, const stack&);
	// 写成这样就不可以
	// friend bool operator== (const stack&, const stack&);
	// friend bool operator< (const stack&, const stack&);

public:
	stack() { cout << "stack" << endl; }
private:
	Sequence c;
};

template <class T, class Sequence>
bool operator==(const stack<T, Sequence>& x,
		const stack<T, Sequence>& y) {
	return cout << "operator==\t";
}

template <class T, class Sequence>
bool operator<(const stack<T, Sequence>& x,
		const stack<T, Sequence>& y) {
	return cout << "operator<\t";
}

int main () {
	stack<int> x;
	stack<int> y;

	cout << (x == y) << endl;
	cout << (x < y) << endl;
}




