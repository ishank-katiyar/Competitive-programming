#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  deque<int> d;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   d.push_back(x);
  }
  while (d.back() == 0) d.pop_back();
  while (d.front() == 0) d.pop_front();
  cout << count (d.begin(), d.end(), 0) << '\n';
 }
 return 0;
}
