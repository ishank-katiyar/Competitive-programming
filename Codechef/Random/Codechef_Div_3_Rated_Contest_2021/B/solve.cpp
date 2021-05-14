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
  vector<int> a (k);
  for  (int i = 0; i < k; i++) {
   cin >> a[i];
  }
  while (n--) {
   string s;
   cin >> s;
   int64_t sum = 0;
   for (int i = 0; i < k; i++) {
    sum += (s[i] == '1' ? a[i] : 0);
   }
   cout << sum << '\n';
  }
 }
 return 0;
}
