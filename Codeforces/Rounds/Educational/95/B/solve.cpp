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
  int sum = 0;
  vector<int> a(n);
  for (auto& i: a) cin >> i, sum += i;
  vector<int> un;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   b[i] = x;
   if (x == 0) {
    un.emplace_back(a[i]);
   }
  }
  sort(un.begin(), un.end());
  if (sum >= 0) reverse(un.begin(), un.end());
  int c = 0;
  for (int i = 0; i < n; i++) {
   if (b[i] == 0) {
    a[i] = un[c++]; 
   }
  } 
  for (auto& i: a) cout << i << ' ';
  cout << '\n';
 }
 return 0;
}
