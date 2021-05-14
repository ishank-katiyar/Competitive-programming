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
 int n;
 cin >> n;
 string s;
 cin >> s;
 vector<vector<int>> a(3);
 for (int i = 0; i < n; i++) {
   a[s[i] - '0'].push_back(i);
 }
 int cnt = n / 3;
	string ss = "";
	int tt = 0;
 int sz1 = max(cnt - (int) a[0].size(), 0);
	tt += sz1;
	while (sz1--) ss += "0";
 sz1 = max(cnt - (int) a[1].size(), 0);
	tt += sz1;
	while (sz1--) ss += "1";
 sz1 = max(cnt - (int) a[2].size(), 0);
	tt += sz1;
	while (sz1--) ss += "2";
	debug(ss, tt);
 vector<int> index;
	int already_done = 0;
 if ((int) a[0].size() > cnt) {
  int sz = (int) a[0].size() - cnt;
		already_done += sz;
  while (sz--) {
    index.push_back(a[0].back());
    a[0].pop_back();
  }
 }
 if ((int) a[2].size() > cnt) {
  int sz = (int) a[2].size() - cnt;
		already_done += sz;
  reverse(a[2].begin(), a[2].end());
  while (sz--) {
    index.push_back(a[2].back());
    a[2].pop_back();
  }
  reverse(a[2].begin(), a[2].end());
 }
 if ((int) a[1].size() > cnt) {
		int need = cnt - (int) a[2].size();
		int mm = min(need, already_done);
		need -= mm;
		already_done -= mm;
 	int sz = need;
  while (sz--) {
    index.push_back(a[1].back());
    a[1].pop_back();
  }
  reverse(a[1].begin(), a[1].end());
		need = cnt - (int) a[0].size();
		mm = min(need, already_done);
		need -= mm;
		already_done -= mm;
 	sz = need;
  while (sz--) {
    index.push_back(a[1].back());
    a[1].pop_back();
  }
  reverse(a[1].begin(), a[1].end());
 }
 sort(index.begin(), index.end());
	debug(index);
	assert (tt == (int) index.size());
	int c = 0;
 for (auto& i: index) {
 	s[i] = ss[c++];
 }	
	cout << s << '\n';
 return 0;
}
