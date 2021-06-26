#include "bits/stdc++.h"
using namespace std;

int main()
{
	set<string> s;
	string a;
	cin >> a;
	cout << a << ' ';
	s.insert(a);
	cin >> a;
	cout << a << '\n';
	s.insert(a);
	int n;
	cin >> n;
	while(n--) {
		cin >> a;
		s.erase(a);
		cin >> a;
		s.insert(a);
		cout << *s.begin() << ' ' << *(++s.begin()) << '\n';
	}
	return 0;
}


