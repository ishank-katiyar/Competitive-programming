#include <bits/stdc++.h>

using namespace std;

string to_string(string s) 																		{ return '"' + s + '"'; }
string to_string(const char* ch) 															{ return string(ch); }
string to_string(char ch) 																		{ return (string)"'" + ch + (string)"'"; }
string to_string(bool b) 																			{ return (b ? "true" : "false"); }
template<class A, class B> string to_string(pair<A, B> p) 		{ return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template<class A> string to_string(A a) {
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
template<class H, class... T> void debug(H head, T... tail) 	{ cerr << to_string(head) << " "; debug(tail...); }

#ifdef LOCAL
	#define debug(...) cerr << "[" << #__VA_ARGS__ << " ] = ["; debug(__VA_ARGS__);
#else 
	#define debug(...) 
#endif

using cd = complex<double>;
const double PI = acos(-1);

void fft_recursive (vector<cd> &a, bool invert) {
	int n = a.size();
	if (n == 1) return;
	vector<cd> a0 (n / 2), a1(n / 2);
	for (int i = 0; i < n / 2; i++) {
		a0[i] = a[2 * i];
		a1[i] = a[2 * i + 1];
	}
	fft_recursive (a0, invert);
	fft_recursive (a1, invert);

	double angle = 2 * PI / n * (invert ? -1 : 1);
	cd w (1), wn (cos(angle), sin(angle));

	for (int i = 0; i < n / 2; i++) {
		a[i] = a0[i] + w * a1[i];
		a[i + n / 2] = a0[i] - w * a1[i];
		if (invert) a[i] /= 2, a[i + n / 2] /= 2;
		w *= wn;
	}
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft_recursive(fa, false);
    fft_recursive(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft_recursive(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	vector<int> aa (a.begin(), a.end()), bb (b.begin(), b.end());
	for_each (aa.begin(), aa.end(), [](int &x) -> int {x -= int('0'); return x;});
	for_each (bb.begin(), bb.end(), [](int &x) -> int {x -= int('0'); return x;});
	reverse (aa.begin(), aa.end());
	reverse (bb.begin(), bb.end());
	debug (aa, bb);
	auto ans = multiply (aa, bb);
	debug (ans);
	int carry = 0;
	for (auto& i: ans) {
		i += carry;
		carry = i / 10;
		i %= 10;
	}
	debug (ans);
	cout << ans.size() << '\n';
	return 0;
}
