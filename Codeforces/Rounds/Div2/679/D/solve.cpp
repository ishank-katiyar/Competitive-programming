#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 vector<pair<char, int>> a (2 * n);

 auto f = [&] (vector<int> A) -> bool {
  vector<int> B (A);
  sort (B.begin(), B.end());
  return A == B;
 };

 vector<int> ch;
 int cnt1 = 0, cnt2 = 0;
 for (int i = 0; i < 2 * n; i++) {
  if (cnt2 > cnt1) {
    cout << "NO" << '\n';
    return 0;
  }
  char c;
  cin >> c;
  a[i].first = c;
  if (c == '+') {
   cnt1++;
   if (f (ch) == false) {
    cout << "NO" << '\n';
    return 0;
   }
   ch.clear();
  }
  else {
   int x;
   cin >> x;
   a[i].second = x;
   cnt2++;
   ch.push_back (x);
  }
 }
 vector<int> ans (n);
 int c = n;
 deque <int> d;
 for (int i = 2 * n - 1; i >= 0; i--) {
  if (a[i].first == '+') {
   c--;
   ans[c] = d.back();
   d.pop_back();
  }
  else {
   d.push_back (a[i].second);
  }
 }
 set <int> s;
 c = -1;
 for (int i = 0; i < 2 * n; i++) {
  if (a[i].first == '+') {
   c++;
   s.insert (ans[c]);
  }
  else {
   if (a[i].second != *s.begin()) {
    cout << "NO" << '\n';
    return 0;
   }
   s.erase (s.begin());
  }
 }
 cout << "YES" << '\n';
 for (auto& i: ans) cout << i << ' ';
 cout << '\n';
 return 0;
}
