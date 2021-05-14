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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int64_t sz = count (s.begin(), s.end(), '*');
		vector<int64_t> suf (n);
		int64_t cnt = sz;
		if (s.back() == '*') suf[n - 1] = n - 1 - (sz - 1), sz--;
		for (int i = n - 2; i >= 0; i--) {
			suf[i] += suf[i + 1] + (s[i] == '*' ? i - (sz - 1) : 0);
			if (s[i] == '*') sz--;
		}
		debug (suf);
		sz = cnt;
		cnt = 0;
		int64_t cur_ans = 0;
		int64_t ans = LLONG_MAX;
		for (int i = 0; i < n; i++) {
			int64_t cur_ans1 = cur_ans;
			int64_t x = (suf[i] - ((sz - cnt) * (i - (cnt))));
			debug (i, x);
			ans = min (ans, cur_ans1 + x);
			if (s[i] == '*') {
				cnt += 1;
			}	else {
				cur_ans += cnt;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
