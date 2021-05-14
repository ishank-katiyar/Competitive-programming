#include <bits/stdc++.h>

using namespace std;

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
 int t;
 cin >> t;
 while (t--) {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> fact;
  for (long long i = 2; i * i <= n; i++) {
   if (n % i) continue;
   int cnt = 0;
   while (n % i == 0) {
    cnt++;
    n /= i;
   }
   fact.emplace_back (i, cnt);
  }
  if (n != 1) fact.emplace_back (n, 1);
  long long pr = 1;
  int mx = 0;
  for (auto& i: fact) {
   if (i.second > mx) {
    mx = i.second;
    pr = i.first;
   }
  }
  vector<long long> ans (mx, pr);
  long long pro = 1;
  for (auto& i: fact) {
   if (i.first != pr) {
    pro *= bpow<long long, long long> (i.first, i.second);
   }
  }
  ans.back() *= pro;
  cout << mx << '\n';
  for (auto& i: ans) cout << i << ' ';
  cout << '\n';
 }
 return 0;
}
