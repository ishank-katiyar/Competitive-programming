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
  int T;
  cin >> T;
  vector<int> a(n);
  for (auto& i: a) cin >> i;
  int cnt = count (a.begin(), a.end(), T / 2);
  cnt /= 2;
  for (auto& i: a) {
   if (T % 2 == 0 && i == T / 2) {
    if (cnt > 0) cout << 1 << ' ';
    else cout << 0 << ' ';
    cnt--;
   }
   else cout << (i <= (T / 2) ? 1 : 0) << ' ';
  }
  cout << '\n';
 }
 return 0;
}
