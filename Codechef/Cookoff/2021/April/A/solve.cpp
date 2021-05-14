#include <bits/stdc++.h>

using namespace std;

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> a (n);
    set <int> s;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s.insert (a[i]);
    }
    int sz = s.size();
    cout << sz - max (0, x - (n - sz)) << '\n';
  }
  return 0;
}
