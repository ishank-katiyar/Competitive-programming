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

typedef long long int ll;

int f(ll n) {
 int ret = 0;
 while(n) ret++, n /= 10;
 return ret;
}

int f1(ll n) {
 int ret = 0;
 while(n) ret += n % 10, n /= 10;
 return ret;
}

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
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  ll n, s;
  cin >> n >> s;
  int dd = f(n);
  if(f1(n) <= s) {
   cout << 0 << '\n';
   continue;
  }
  if(n / bpow((ll)10, dd - 1) >= s) {
   ll ans = bpow((ll)10, dd) - n;
   cout << ans << '\n';
   continue;
  }
  vector<int> a(dd);
  ll nn = n;
  for(int i = dd - 1; i >= 0; i--) a[i] = nn % 10, nn /= 10;
  debug(a);
  int sum = 0;
  ll n2 = 0;
  for(int i = 0; i < dd; i++) {
   sum += a[i];
   n2 += a[i] * bpow((ll)10, dd - i - 1);
   if(sum >= s) {
    a[i-1]++;
    for(int j = i; j < dd; j++) a[j] = 0;
    break;
   }
  }
  debug(a);
  n2 = 0;
  int carry = 0;
  for(int i = dd-1; i >= 0; i--) {
   a[i] += carry;
   carry = a[i] / 10;
   a[i] %= 10;
  }
  a[0] += carry * 10;
  debug(a);
  for(int i = 0; i < dd; i++) {
   n2 += a[i] * bpow((ll)10, dd - i - 1);
  }
  debug(n2);
  cout << n2 - n << '\n';
 }
 return 0;
}
