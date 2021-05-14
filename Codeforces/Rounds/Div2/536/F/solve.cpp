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

const int mod = 998244353;

template<class X> class matrix {
public:
	int row, column;

	vector<vector<X>> M;

	matrix() {
		row = column = 0;
		M.assign(row, vector<X>(column));
	}

	matrix(vector<vector<X>> MM) {
		row = (int) MM.size(), column = (int) MM[0].size();
		M = MM;
	}

	matrix (int r) {
		row = r, column = r;
		M.assign(row, vector<X> (column));
		for (int i = 0; i < row; i++) M[i][i] = X(1);
	}

	matrix(int r , int c) {
		row = r, column = c;
		M.assign(row , vector<X> (column));
	}

	matrix(int r , int c , X value) {
		row = r, column = c;
		M.assign(row , vector<X> (column , value));
	}

	vector<X>& operator [] (int idx) {
		if(idx < 0 || idx >= row) { throw out_of_range("In matrix : " + to_string(idx) + " is out of range [0 , " + to_string(row - 1) + "]"); }
		return M[idx];
	}

	template<class T> ostream& operator << (matrix<T> a);

	matrix operator + (matrix b);
	matrix operator - (matrix b);
	matrix operator * (matrix b);
	matrix operator / (matrix b);
	matrix operator + (X b);
	matrix operator - (X b);
	matrix operator * (X b);
	matrix operator / (X b);
	matrix operator ^ (int64_t b);

	void operator += (matrix a);
	void operator -= (matrix a);
	void operator *= (matrix a);
	void operator /= (matrix a);
	void operator += (X b);
	void operator -= (X b);
	void operator *= (X b);
	void operator /= (X b);
	void operator ^= (int64_t b);
	bool operator == (matrix a);
	bool operator != (matrix a);

	matrix transpose();
};

template<class T> ostream& operator << (ostream& out , matrix<T> a) {
	int row = a.row, column = a.column;
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < column; j++) out << a[i][j] << ' ';
		out << " \n"[i != row - 1];
	}
	return out;
}

template<class X> matrix<X> matrix<X>::operator + (matrix<X> b) {
	if(row != b.row || column != b.column) { throw logic_error("Addition of matrices with different Dimensions"); }
	for(int i = 0; i < row; i++) { for(int j = 0; j < column; j++) M[i][j] += b[i][j]; }
	return *this;
}

template<class X> matrix<X> matrix<X>::operator - (matrix<X> b) {
	if(row != b.row || column != b.column) { throw logic_error("Subtraction of matrices with different Dimensions"); }
	for(int i = 0; i < row; i++) { for(int j = 0; j < column; j++) M[i][j] -= b[i][j]; }
	return *this;
}

template<class X> matrix<X> matrix<X>::operator * (matrix<X> b) {
	if(column != b.row) { throw logic_error("Multiplication of martices with different Dimensions"); }
	int r = row, col = b.column;
	matrix<X> ret(r , col);
	for(int i = 0; i < r; i++) { for(int j = 0; j < col; j++) { for(int k = 0; k < column; k++) (ret[i][j] += (M[i][k] * b[k][j])) %= (mod - 1); } }
	return ret;
}

template<class X> matrix<X> matrix<X>::operator / (matrix<X> b) { return *this * inv(b); }
template<class X> matrix<X> matrix<X>::operator + (X b) 				{ return *this + matrix(row , column , b); }
template<class X> matrix<X> matrix<X>::operator - (X b) 				{ return *this - matrix(row , column , b); }
template<class X> matrix<X> matrix<X>::operator * (X b) 				{ for(int i = 0; i < row; i++) { for(int j = 0; j < column; j++) M[i][j] *= b; } return *this; }
template<class X> matrix<X> matrix<X>::operator / (X b) 				{ for(int i = 0; i < row; i++) { for(int j = 0; j < column; j++) M[i][j] /= b; } return *this; }
template<class X> matrix<X> matrix<X>::operator ^ (int64_t b) 	{ matrix<X> ret = *this, a = *this; b--; while(b) { if(b % 2 == 1) ret = ret * a; a = a * a, b /= 2; } return ret; }

template<class X> void matrix<X>::operator += (matrix<X> b) 		{ *this = *this + b; }
template<class X> void matrix<X>::operator -= (matrix<X> b) 		{ *this = *this - b; }
template<class X> void matrix<X>::operator *= (matrix<X> b) 		{ *this = *this * b; }
template<class X> void matrix<X>::operator /= (matrix<X> b) 		{ *this = *this / b; }
template<class X> void matrix<X>::operator += (X b) 						{ *this = *this + b; }
template<class X> void matrix<X>::operator -= (X b) 						{ *this = *this - b; }
template<class X> void matrix<X>::operator *= (X b) 						{ *this = *this * b; }
template<class X> void matrix<X>::operator /= (X b) 						{ *this = *this / b; }
template<class X> void matrix<X>::operator ^= (int64_t b) 			{ *this = *this ^ b; }
template<class X> bool matrix<X>::operator == (matrix<X> a) 		{ for(int i = 0; i < row; i++) { for(int j = 0; j < column; j++) if(M[i][j] != a[i][j]) return false; } return true; }
template<class X> bool matrix<X>::operator != (matrix<X> a) 		{return !(*this == a);}

template<class X> matrix<X> matrix<X>::transpose() {
	if (row != column) { throw logic_error("Cannot Transpose an NON-SQUARE matrix"); }
	matrix<X> ret(column , row);
	for(int i = 0; i < column; i++) { for(int j = 0; j < row; j++) { ret[i][j] = M[j][i]; } }
	return ret;
}

int gcd(int a, int b) {
	return a ? gcd(b % a, a) : b;
}

int powmod(int a, int b, int p) {
	int res = 1;
	while (b > 0) {
			if (b & 1) {
					res = res * 1ll * a % p;
			}
			a = a * 1ll * a % p;
			b >>= 1;
	}
	return res;
}

// Finds the primitive root modulo p
int generator(int p) {
    vector<int> fact;
    int phi = p-1, n = phi;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fact.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        fact.push_back(n);

    for (int res = 2; res <= p; ++res) {
        bool ok = true;
        for (int factor : fact) {
            if (powmod(res, phi / factor, p) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return res;
    }
    return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int K;
	cin >> K;
	vector<int> b (K);
	for (int i = 0; i < K; i++) {
		cin >> b[i];
	}
	int nn, m;
	cin >> nn >> m;

	auto pw = [] (int N, const vector<int> B, const int P) -> int {
		const int k = B.size();
		vector<vector<int64_t>> aa (k, vector<int64_t> (k));
		for (int i = 0; i < k; i++) { aa[0][i] = B[i]; }
		for (int i = 1; i < k; i++) { aa[i][i - 1] = 1; }
		matrix<int64_t> M (aa);
		M ^= (N - k);
		vector<vector<int64_t>> a (k, vector<int64_t> (1, 0));
		a[0][0] = 1;
		matrix<int64_t> F (a);
		M *= F;
		return P - 1 + (M[0][0]) % (P - 1);
	};

	int n, k, a;
	n = mod;
	k = pw (nn, b, mod);
	a = m;

	int g = generator(n);

	int sq = (int) sqrt (n + .0) + 1;
	debug (a, g, k, n, sq);
	map<int, int> mp;
	for (int q = 0; q <= sq; ++q)
		mp[powmod(g, (q * 1ll * k % (n - 1)) + (n - 1), n) * 1ll * a % n] = q;
	debug (mp);
	int any_ans = -1;
	for (int p = 1; p <= sq; ++p) {
		int my = powmod(g, (p * 1ll * sq * k % (n - 1)) + (n - 1), n);
		if (mp.count (my)) {
			any_ans = p * sq - mp[my];
			break;
		}
	}
	if (any_ans == -1) {
		cout << -1 << '\n';
		return 0;
	}
	cout << powmod (g, any_ans, mod) << '\n';
	return 0;
}
