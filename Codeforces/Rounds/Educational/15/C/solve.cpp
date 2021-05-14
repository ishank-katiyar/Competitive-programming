#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 int m;
 cin >> m;
 vector<long long int> a(n);
 for (auto& i: a) cin >> i;
 multiset<long long int> s;
 for (int i = 0; i < m; i++) {
  int x;
  cin >> x;
  s.insert (x);
 }

 auto check = [&] (long long int R) -> bool {
  bool ok = true;
  for (int i = 0; i < n; i++) {
   auto it = s.lower_bound(a[i] - R);
   if (it == s.end()) return false;
   ok &= (abs(*it - a[i]) <= R);
  }
  return ok;
 };

 long long int low = 0, high = 1e15;
 while (low < high) {
  long long int mid = (low + high) >> 1;
  if (check(mid) == true) high = mid;
  else low = mid + 1;
 }
 cout << low << '\n'; 
 return 0;
}
