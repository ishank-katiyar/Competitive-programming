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
  if (count (s.begin(), s.end(), '*') == 1) {
   cout << 1 << '\n';
   continue;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
   if (s[i] == '*') {
    s[i] = 'x';
    break;
   }
  }
  int last = -1;
  for (int i = n - 1; i >= 0; i--) {
   if (s[i] == '*') {
    s[i] = 'x';
    last = i;
    break;
   }
  }
  ans = 2;
  int i = 0;
  while (i < n) {
   if (i >= last) {
    break;
   }
   if (s[i] != 'x') {
    i += 1;
    continue;
   }
   int j = min (n - 1, i + k);
   bool ok = false;
   for (int K = j; K >= i + 1; K--) {
    if (s[K] == 'x') {
     ok = true;
     j = K;
     break;
    }
   }
   if (ok == true) {
    i = j;
   } else {
    for (int K = j; K >= i; K--) {
     if (s[K] == '*') {
      j = K;
      s[K] = 'x';
      ans += 1;
      break;
     }
    }
    i = j;
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
