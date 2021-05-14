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

template<class X, class Y>
X bpow(X a , Y b) {
 X res(1);
 while(b) {
  if(b % 2 == 1) res *= a;
  a *= a;
  b /= 2;
 }
 return res;
}

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int test_case = 0;
 cin >> test_case;
 for (int ttt = 1; ttt <= test_case; ttt++) {
  cout << "Case #" << ttt << ": ";
  long long l, r;
  cin >> l >> r;
  auto f = [] (long long n) -> long long {
   if (n == 0) return 0;
   string S = to_string (n);
   int sz = (int) S.size();
   long long ans = 0;
   int NN = sz - 1;
   ans += 5 * ((bpow<long long, long long> (5, NN) - 1) / (4));
   bool bb = false;
   for (int i = 1; i <= sz - 1; i++) {
    if (i % 2 == 1) {
     long long int dd = int (S[i - 1] - '0');
     long long int rest = dd / 2;
     ans += rest * bpow <long long, long long> (5, sz - i);
     if (dd % 2 == 0) {
      bb = true;
      break;
     }
    }
    else {
     long long int dd = int (S[i - 1] - '0');
     long long int rest = (dd + 1) / 2;
     ans += rest * bpow <long long, long long> (5, sz - i);
     if (dd % 2 == 1) {
      bb = true;
      break;
     }
    }
   }
   if (bb == false) {
    if (sz % 2 == 1) {
     long long dd = int (S[sz - 1] - '0');
     ans += (dd + 1) / 2;
    }
    else {
     long long dd = int (S[sz - 1] - '0');
     if (dd % 2 == 0) {
      ans += (dd / 2) + 1;
     }
     else {
      ans += (dd + 1) / 2;
     }
    }
   }
   debug (n, ans);
   return ans;
  };
  cout << f (r) - f (l - 1) << '\n';
 }
 return 0;
}
