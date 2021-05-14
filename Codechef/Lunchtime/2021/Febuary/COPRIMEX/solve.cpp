#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 const int maxn = static_cast <int> (2e6);
 vector<bool> is (maxn, true);
 vector<int> prime;
 for (int i = 2; i < maxn; i++) {
  if (is[i]) {
   prime.push_back (i);
   for (int j = 2 * i; j < maxn; j += i) {
    is[j] = false;
   }
  }
 }
 int t;
 cin >> t;
 while (t--) {
  int l, r;
  cin >> l >> r;
  cout << *upper_bound (prime.begin(), prime.end(), r) << '\n';
 }
 return 0;
}
