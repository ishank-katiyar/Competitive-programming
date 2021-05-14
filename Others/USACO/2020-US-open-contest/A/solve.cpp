#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
#ifndef LOCAL
 freopen ("socdist1.in", "r", stdin);
 freopen ("socdist1.out", "w", stdout);
#endif
 int n;
 cin >> n;
 string s;
 cin >> s;

 auto f = [&](int mid) -> bool {
  vector<int> a;
  for (int i = 0; i < n; i++) {
   if (s[i] == '1') a.push_back (i);
  }
  if (a.empty() == true) {
   return mid <= n - 1;
  }
  int sz = static_cast <int> (a.size());
  for (int i = 1; i < sz; i++) {
   if (a[i] - a[i - 1] < mid) return false;
  }
  int cnt = 2;
  if (a.front() >= 2 * mid) {
   cnt -= 2;
   return true;
  } else if (a.front() >= mid) {
   cnt -= 1;
  }
  if (n - a.back() - 1 >= 2 * mid) {
   cnt -= 2;
   return true;
  } else if (n - a.back() - 1 >= mid) {
   cnt -= 1;
   if (cnt <= 0) return true;
  }
  for (int i = 1; i < sz; i++) {
   if (a[i] - a[i - 1] - 1 >= 3 * (mid - 1) + 2) {
    cnt -= 2;
    return true;
   } else if (a[i] - a[i - 1] - 1 >= 2 * (mid - 1) + 1) {
    cnt -= 1;
    if (cnt <= 0) return true;
   }
  }
  return false;
 };

 int low = 1, high = n;
 while (low < high) {
  int mid = (low + high) / 2;
  if (f (mid) == false) high = mid;
  else low = mid + 1;
 }
 if (f (low) == false) low--;
 assert ([&]() -> bool {
  if (f (low) == false) cout << low << '\n';
  return f (low);
 }());
 cout << low << '\n';
 return 0;
}
