#include <bits/stdc++.h>

using namespace std;

template<typename T>
class MinQueue {
protected:
	deque<T> d;
public:
	MinQueue () {}
};

template<typename T>
class RangeQuery : public MinQueue<T> {
	using MinQueue<T>::d;
public:
	RangeQuery () {}
	T get () {
		assert (d.empty () == false);
		return d.front();
	}
	void add (T x) {
		while (d.empty() == false && d.back() > x) d.pop_back();
		d.push_back(x);
	}
	void remove (T x) {
		if (d.empty() == false && d.front() == x) d.pop_front();
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
