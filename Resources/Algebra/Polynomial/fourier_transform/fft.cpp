#include <bits/stdc++.h>

using namespace std;

using cd = complex<double>;
const double PI = acos (-1);

class FFT {
public:
	static int base;
	static vector<int> rev;
	static vector<cd> roots;

	static void init() {
		rev = {0, 1};
		roots = vector<cd> (2, 1);
		base = 1;
	}

	static void ensure_base (int new_base) {
		if (roots.empty() || rev.empty()) { init(); }
		if (base >= new_base) { return; }
		rev.resize(1 << new_base);
		for (int i = 0; i < (1 << new_base); i++) { rev[i] = ((rev[i / 2] >> 1) | (i % 2) << (new_base - 1)); }
		roots.resize (1 << new_base);
		while (base < new_base) {
			const auto z = polar (1.0, PI / (1 << base));
			for (int i = (1 << (base - 1)); i < (1 << base); i++) {
				roots[i << 1] = roots[i];
				roots[(i << 1) + 1] = roots[i] * z; 
			}
			base++;
		}
	}

	static void fft (vector<cd> &a) {
		int n = a.size();
		int zeros = __builtin_ctz (n);
		ensure_base (zeros);
		int shift = base - zeros;
		for (int i = 0; i < n; i++) { if (i < (rev[i] >> shift)) swap (a[i], a[rev[i] >> shift]); }
		for (int k = 1; k < n; k *= 2) { 
			for (int i = 0; i < n; i += 2 * k) {
				for (int j = 0; j < k; j++) {
					auto x = a[i + j], y = a[i + j + k] * roots[k + j];
					a[i + j] = x + y;
					a[i + j + k] = x - y;
				}
			}
		}
	}

	template<typename T> 
	static vector<T> multiply (vector<T> a, vector<T> b) {
		if (a.empty() || b.empty()) return {};
		int total = int (a.size() + b.size()) - 1;
		int n = 1 << (32 - __builtin_clz(total));
		vector<cd> A (a.begin(), a.end()), B (b.begin(), b.end());
		A.resize (n), B.resize (n);
		fft (A);
		if (A != B) fft (B); else B = A;
		for (int i = 0; i < n; i++) { A[i] *= B[i] / cd (n); }
		fft (A);
		reverse (A.begin() + 1, A.end());
		vector<T> res (total);
		for (int i = 0; i < total; i++) {
			res[i] = round(A[i].real());
		}
		return res;
	}
};

int FFT::base;
vector<int> FFT::rev;
vector<cd> FFT::roots;

template<typename T> vector<T> operator *  (const vector<T>& A, const vector<T>& B) { 
	if (A.empty() || B.empty()) { return {}; }
	if (min ((int) A.size(),(int) B.size()) <= 250) {
		vector<T> C ((int) A.size() + (int) B.size() - 1, 0);
		for (int i = 0; i < (int) A.size(); i++) {
			for (int j = 0; j < (int) B.size(); j++) {
				C[i + j] += A[i] * B[j];
			}
		}
		return C;
	}
	return FFT::multiply <T> (A, B); 
}
template<typename T> vector<T> operator *= (vector<T>& A, const vector<T>& B) { return A = A * B; }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
