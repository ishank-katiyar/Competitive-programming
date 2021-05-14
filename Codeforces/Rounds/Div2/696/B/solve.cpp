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

const int maxn = static_cast <int> (2e5 + 1);
vector<int64_t> prime;
vector<bool> is (maxn, true);

void seive() {
 is[0] = is[1] = false;
 for (int i = 2; i < maxn; i++) {
  if (is[i] == true) {
   prime.push_back (i);
   for (int j = 2 * i; j < maxn; j += i) {
    is[j] = false;
   }
  }
 }
}

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 seive();
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  if (n == 1) {
   cout << 6 << '\n';
   continue;
  }
  auto it = upper_bound(prime.begin(), prime.end(), n);
  int64_t x1 = *it;
  it = upper_bound(prime.begin(), prime.end(), x1 + n - 1);
  int64_t x2 = *it;
  cout << x1 * x2 << '\n';
 }
 return 0;
}
