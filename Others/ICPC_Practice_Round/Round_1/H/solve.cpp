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
	int n;
	cin >> n;
	assert (n >= 2);
	vector<int> a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort (a.begin(), a.end());
	if (n == 2) {
		cout << a[0] << ' ' <<  a[1] << '\n';
		return 0;
	}
	int idx1 = (n - 1) / 2, idx2 = idx1 + 1;
	bool ok = false;
	vector<int> ans;
	ans.push_back (a[idx1]);
	idx1 -= 1;
	while (true) {
		if (ok) {
			if (idx1 >= 0) {
				ans.push_back (a[idx1]);
				idx1 -= 1;
			}
		}	else {
			if (idx2 < n) {
				ans.push_back (a[idx2]);
				idx2 += 1;
			}
		}
		ok ^= 1;
		if (idx1 < 0 && idx2 >= n) break;
	}
	assert ((int)ans.size() == n);
	debug (ans);
	for (int i = 2; i < n; i++) {
		debug (ans[i] - ans[i - 1]);
		debug (ans[i - 1] - ans[i - 2]);
		assert (abs(ans[i] - ans[i - 1]) >= abs(ans[i - 1] - ans[i - 2]));
	}
	for (auto& i: ans) cout << i << ' ';
	cout << '\n';
	return 0;
}
