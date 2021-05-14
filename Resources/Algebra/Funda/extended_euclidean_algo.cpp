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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd() {
	return uniform_int_distribution<int> (1, (int) 1e9) (rng);
}

template<class A> 
A rnd(A x, A y) {
	return uniform_int_distribution<A> (x, y) (rng);
}

namespace euclid {
/*
* rule = gcd (a, b) = gcd (b, a ope b);
* ope = any operation which doesnt add there factors together (like multiply,
* divide) valid ope = %, + , - invalid ope = *, /
* example:- gcd (a, b) = gcd (b, a % b)
* example:- gcd (a, b) = gcd (b, a - b)
*/

template<class T> 
T extended_gcd_iterative(T a , T b , T& x , T& y) {
	/* Original code
		if(b == 0) { x = 1 , y = 0; return a; }
		T x1 , y1;
		T gd = gcd(b , a % b , x1 , y1);
		x = y1;
		y = x1 - (a / b) * y1;
		return gd; 
	*/
	x = T(1), y = T(0);
	T x1 = 0, y1 = 1, a1 = a, b1 = b;
	while (b1) {
		T q = a1 / b1;
		tie(x, x1) = make_pair (x1, x - q * x1);
		tie(y, y1) = make_pair (y1, y - q * y1);
		tie(a1, b1) = make_pair (b1, a1 - q * b1);
	}
	return a1;
}

template<class T>
vector<pair<T, T>> dophantine_equation (T a, T b, T c, bool get_only_one_solution = false, T Xmin = -1e6, T Xmax = 1e6, T Ymin = -1e6, T Ymax = 1e6) {
	auto valid_x = [&] (const T x) -> bool { return x <= Xmax && x >= Xmin; };
	auto valid_y = [&] (const T y) -> bool { return y <= Ymax && y >= Ymin; };

	// Trivial cases
	if (a == 0 && b == 0) {
		if (c == 0) {
			vector<pair<T, T>> ret;
			for (T i = Xmin; i <= Xmax; i += 1) for (T j = Ymin; j <= Ymax; j += 1) { ret.push_back (make_pair(i, j)); }
			return ret;
		} else {
			return {};
		}
	}
	if (b == 0) {
		if (c % a || valid_x(c / a) == false) {
			return {};
		}
		vector<pair<T, T>> ret;
		for (T i = Ymin; i <= Ymax; i += 1) { ret.push_back (make_pair (c / a, i)); }
		return ret;
	}
	if (a == 0) {
		if (c % b || valid_y(c / b) == false) {
			return {};
		}
		vector<pair<T, T>> ret;
		for (T i = Xmin; i <= Xmax; i += 1) { ret.push_back (make_pair (i, c / b)); }
		return ret;
	} // trivial cases done

	T X_FIRST = 0, Y_FIRST = 0;
	T gcd = extended_gcd_iterative (abs (a), abs (b), X_FIRST, Y_FIRST);
	if (c % gcd != 0) { return {}; }
	X_FIRST *= (c / gcd) * (a < 0 ? -1 : 1);
	Y_FIRST *= (c / gcd) * (b < 0 ? -1 : 1);
	vector<pair<T, T>> ret;
	a /= gcd;
	b /= gcd;
	c /= gcd;
	auto shift_soln = [&] (const int K) { X_FIRST += K * b, Y_FIRST -= K * a; };
	shift_soln ((Xmin - X_FIRST) / b);
	if (X_FIRST < Xmin) { shift_soln (b < 0 ? -1 : 1); }
	if (X_FIRST > Xmax) { return {}; }
	T minx1 = X_FIRST;
	shift_soln ((Xmax - X_FIRST) / b);
	if (X_FIRST > Xmax) { shift_soln (b < 0 ? 1 : -1); }
	T maxx1 = X_FIRST;
	shift_soln (-(Ymin - Y_FIRST) / a);
	if (Y_FIRST < Ymin) { shift_soln (a < 0 ? 1 : -1); }
	if (Y_FIRST > Ymax) { return {}; }
	T minx2 = X_FIRST;
	shift_soln (-(Ymax - Y_FIRST) / a);
	if (Y_FIRST > Ymax) { shift_soln (a < 0 ? -1 : 1); }
	T maxx2 = X_FIRST;

	if (minx2 > maxx2) {swap (minx2, maxx2); }

	T minx = max (minx1, minx2);
	T maxx = min (maxx1, maxx2);

	for (T i = minx; i <= maxx; i += abs(b)) {
		ret.push_back (make_pair (i, (c - a * i) / b));
		if (ret.empty() == false && get_only_one_solution) {
			return ret;
		}
	}
	return ret;
}

}; // end of namespace euclid

using namespace euclid;

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
	// const int x = 5;
	// auto check = [&] (const int a, const int b, const int c) {
	// 	debug (a, b, c);
	// 	vector<pair<int, int>> ans;
	// 	for (int i = -x; i <= x; i++) {
	// 		for (int j = -x; j <= x; j++) {
	// 			if (a * i + b * j == c) {
	// 				ans.push_back (make_pair (i, j));
	// 			}
	// 		}
	// 	}
	// 	// sort (ans.begin(), ans.end(), [] (const pair <int, int> A, const pair <int, int> B) -> bool {
	// 	// 	if (A.first == B.first) return A.second < B.second;
	// 	// 	return A.first < B.first;
	// 	// });
	// 	auto ret = dophantine_equation (a, b, c, false, -x, x, -x, x);
	// 	// sort (ret.begin(), ret.end(), [] (const pair <int, int> A, const pair <int, int> B) -> bool {
	// 	// 	if (A.first == B.first) return A.second < B.second;
	// 	// 	return A.first < B.first;
	// 	// });
	// 	debug (ans);
	// 	debug (ret);
	// 	assert (ret == ans);
	// };
	// for (int i = -x; i <= x; i++) {
	// 	for (int j = -x; j <= x; j++) {
	// 		for (int k = -x; k <= x; k++) {
	// 			check (i, j, k);
	// 		}
	// 	}
	// }
  return 0;
}
