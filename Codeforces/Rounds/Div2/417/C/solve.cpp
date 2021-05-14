#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 ll S;
 cin >> S;
 vector<ll> a(n);
 for (auto& i: a) cin >> i;
 auto f = [&] (int K) -> ll {
  vector<ll> A(a);
  for (ll i = 1; i <= n; i++) A[i - 1] += i * K;
  sort (A.begin(), A.end());
  ll ret = 0;
  for (int i = 0; i < K; i++) ret += A[i];
  return ret;
 };
 int low = 1, high = n;
 while (low < high) {
  int mid = (low + high) >> 1;
  if (f(mid) > S) high = mid;
  else low = mid + 1;
 }
 if (f(low) > S) low--;
 cout << low << ' ' << f(low) << '\n'; 
 return 0;
}
