#include <iostream>
#include <cstddef>
using namespace std;

class alloc {};

inline size_t __deque_buf_size(size_t n, size_t sz) {
	return n != 0 ? n : (sz < 512 ? size_t(512 / sz) : size_t(1));
}

template <class T, class Ref, class Ptr, size_t BufSize>
struct __deque_iterator {
	typedef __deque_iterator<T, T&, T*, BufSize> iterator;
	typedef __deque_iterator<T, const T&, const T*, BufSize> const_iterator;
	static size_t buffer_size() {
		return __deque_buf_size(BufSize, sizeof(T));
	}
};

template <class T, class Alloc = alloc, size_t BufSize = 0>
class deque {
public:
	typedef __deque_iterator<T, T&, T*, BufSize> iterator;
};

int main() {
	cout << deque<int>::iterator::buffer_size() << endl;
	cout << deque<int, alloc, 64>::iterator::buffer_size() << endl;
}
