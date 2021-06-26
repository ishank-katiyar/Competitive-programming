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
	vector<string> a;	
	string s;
	while (cin >> s) a.push_back (s);
	debug (a);
	assert (a.size() % 2 == 0);
	int n = a.size();
	set<char> ans;
	for (int i = 0; i < n / 2; i++) {
		string s1 = a[i];
		int sz1 = s1.size();
		string s2 = a[i + n / 2];
		int sz2 = s2.size();
		int idx1 = 0, idx2 = 0;
		while (idx1 < sz1 && idx2 < sz2) {
			int len1 = 0, len2 = 0;
			char ch1 = s1[idx1], ch2 = s2[idx2];
			assert (ch1 == ch2);
			while (idx1 < sz1 && s1[idx1] == ch1) idx1 += 1, len1 += 1;
			while (idx2 < sz2 && s2[idx2] == ch2) idx2 += 1, len2 += 1;
			if (len1 == len2) continue;
			if (len1 > len2) swap (len1, len2);
			assert (2 * len1 == len2);
			ans.insert (ch1);
		}
	} 
	for (auto& i: ans) cout << i;
	cout << '\n';
	return 0;
}
