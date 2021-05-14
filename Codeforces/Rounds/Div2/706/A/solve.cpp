#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int cnt = 0;
  deque<char> d;
  for (auto& i: s) {
   d.push_back (i);
  }
  while (static_cast <int> (d.size()) > 1 && d.front() == d.back()) {
   cnt++;
   d.pop_back();
   d.pop_front();
  }
  if (d.empty()) {
   cnt -= 1;
  }
  cout << (cnt >= k ? "YES" : "NO") << '\n';
 }
 return 0;
}
