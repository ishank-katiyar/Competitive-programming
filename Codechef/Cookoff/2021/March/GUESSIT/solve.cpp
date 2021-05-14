#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 const int maxn = static_cast <int> (1e6 + 1);
 vector<int> factor_cnt (maxn, 0);
 for (int i = 1; i < maxn; i++) {
  for (int j = i; j < maxn; j += i) {
   factor_cnt[j] += 1;
  }
 }
 vector<int> aa;
 for (int i = 1; i < maxn; i++) {
  if (factor_cnt [i] % 2 == 1) {
   aa.push_back (i);
  }
 }
 int t;
 cin >> t;
 while (t--) {
  for (auto& i: aa) {
   cout << i << endl;
   int x;
   cin >> x;
   if (x == -1) {
    exit(0);
   }
   if (x == 0) {
    continue;
   }
   break;
  }
 }
 return 0;
}
