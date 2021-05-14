#include <bits/stdc++.h>

using namespace std;

template<class A, class B, class C> string to_string(priority_queue<A, B, C> a) {
	vector<A> res;
	while(a.empty() == false) { res.push_back(a.top()); a.pop(); }
	reverse(res.begin(), res.end());
	return to_string(res);
}

template<class A> string to_string(priority_queue<A> a) {
	vector<A> res;
	while(a.empty() == false) { res.push_back(a.top()); a.pop(); }
	reverse(res.begin(), res.end());
	return to_string(res);
}

template<class A> string to_string(stack<A> a) {
	vector<A> res;
	while(a.empty() == false) { res.push_back(a.top()); a.pop(); }
	return to_string(res);
}

template<class A> string to_string(queue<A> a) {
	vector<A> res;
	while(a.empty() == false) { res.push_back(a.front()); a.pop(); }
	return to_string(res);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}