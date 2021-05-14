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

typedef long long ll;

vector<ll> subset_sum;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 int w;
 cin >> w;
 vector<pair<ll, ll>> a(n);
 int t_sum = 0;
 for(auto& i: a) cin >> i.first >> i.second, t_sum += i.second;
 subset_sum.assign(t_sum+1, 1e9);
 subset_sum[0] = 0;
 for(int i = 0; i < n; i++) {
  for(int j = t_sum; j >= a[i].second; j--) {
   subset_sum[j] = min(subset_sum[j], subset_sum[j - a[i].second] + a[i].first);
  }
 }
 debug(subset_sum);
 int ans = 0;
 for(int i = t_sum; i >= 1; i--) {
  if(subset_sum[i] <= w) {
   ans = i;
   break;
  }
 }
 cout << ans << '\n';
 return 0;
}
