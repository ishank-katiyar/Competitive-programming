#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
	return '"' + s + '"';
}

string to_string(const char* ch) {
	return to_string((string)ch);
}

string to_string(char ch) {
	return (string)"'" + ch + (string)"'";
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

template<class A, class B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<class A>
string to_string(A a) {
	string res = "{";
	bool first = true;
	for(const auto& x: a) {
		if(first == false) res += ", ";
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

void debug() {cerr << "]\n";}

template<class H, class... T>
void debug(H head, T... tail) {
	cerr << to_string(head) << " ";
	debug(tail...);
}

#ifdef LOCAL
	#define debug(...) cerr << "[" << #__VA_ARGS__ << " ] = ["; debug(__VA_ARGS__);
#else 
	#define debug(...) 
#endif

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& i: a) cin >> i;
		const int bit = 32;
  vector<int> c(bit);
		long long int ans = 0;
		int X = 32 - __builtin_clz(a[0]) - 1;
		c[X]++;
		debug(0, c);
		for (int i = 1; i < n; i++) {
			int x = 32 - __builtin_clz(a[i]) - 1;
			ans += c[x];
			c[x]++;
		 debug(i, c);
		}
		cout << ans << '\n';
	}
	return 0;
}
