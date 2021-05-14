#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 vector<int> a (n + 1);
 for (int i = 1; i <= n; i++) {
  cin >> a[i];
 }
 vector<int> b (n + 1);
 for (int i = 1; i <= n; i++) {
  cin >> b[i];
 }
 set <pair<int, int>> bribed;
 set <int> s;
 for (int i = 1; i <= n; i++) {
  s.insert (i);
 }
 int ans = 0;
 for (int i = 1; i <= n; i++) {
  if (a[i] != *(s.begin())) {
   bribed.insert (pair (a[i], i));
  }
  else {
   s.erase (s.begin());
   while (s.empty() == false && *(s.begin()) == (bribed.begin()->first)) {
    int coins = i - (bribed.begin()->second);
    int N = (bribed.begin()->first);
    if (b[N] < coins) {
     cout << -1 << '\n';
     return 0;
    }
    ans += coins;
    s.erase (s.begin());
    bribed.erase (bribed.begin());
   }
  }
 }
 assert (s.empty() == true);
 assert (bribed.empty() == true);
 cout << ans << '\n';
 return 0;
}

/*
 * 5 1 2 3 4
 * 5 2 1 3 4
 *
 * 1 2 3 4 5
 * 1 3 2 4 5
 * 5 1 3 2 4
 * 5 2 1 3 4
 */
