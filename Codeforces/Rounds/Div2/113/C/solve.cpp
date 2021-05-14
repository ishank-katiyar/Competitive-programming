#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 int x;
 cin >> x;
 vector<int> a(n);
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }
 int ans = 0;
 if (count (a.begin(), a.end(), x) == 0) a.push_back(x), ans++, n++;
 while (1) {
  sort (a.begin(), a.end());
  int idx1 = upper_bound (a.begin(), a.end(), x) - a.begin();
  assert (idx1 > 0);
  idx1--;
  assert (a[idx1] == x);
  int idx = lower_bound (a.begin(), a.end(), x) - a.begin();
  int X = ((n - 1) / 2);
  if (idx <= X && idx1 >= X) break;
  ans++;
  if (idx1 < X) a.insert (a.begin(), 1);
  else if (idx > X) a.push_back((int)1e5);
  else assert (false);
  n++;
  //cerr << n << endl;
 }
 cout << ans << '\n';
 return 0;
}
