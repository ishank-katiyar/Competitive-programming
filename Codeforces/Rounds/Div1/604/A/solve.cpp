#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i: a) cin >> i;
  reverse (a.begin(), a.end());
  int g = 0;
  int prev = a.back();
  while (a.empty() == false && a.back() == prev) g++, a.pop_back();
  int sz = n / 2  - g;
  if (sz <= 0) {
   cout << "0 0 0\n";
   continue;
  }
  vector<int> aa;
  while (sz--) aa.push_back(a.back()), a.pop_back();
  while (aa.empty() == false && aa.back() == a.back()) aa.pop_back();
  sz = (int) aa.size();
  int s = 0, b = 0;
  for (int i = g + 1; i < sz; i++) {
   if (aa[i] != aa[i - 1]) {
    s = i;
    b = sz - s;
    break;
   }
  }
  if (g >= s || g >= b || b <= 0 || s <= 0) g = s = b = 0;
  cout << g << ' ' << s << ' ' << b << '\n';
 }
 return 0;
}
