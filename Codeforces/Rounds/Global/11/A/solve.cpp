#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> a, b;
  int cnt = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   if (x > 0) a.push_back(x);
   else if (x == 0) cnt++;
   else b.push_back(x);
   sum += x;
  }
  if (sum == 0) {
   cout << "NO" << '\n';
   continue;
  }
  cout << "YES" << '\n';
  if (sum < 0) {
   for (auto& i: b) cout << i << ' ';
   while (cnt--) cout << 0 << ' ';
   for (auto& i: a) cout << i << ' ';
  }
  else {
   for (auto& i: a) cout << i << ' ';
   while (cnt--) cout << 0 << ' ';
   for (auto& i: b) cout << i << ' ';
  }
  cout << '\n'; 
 }
 return 0;
}
