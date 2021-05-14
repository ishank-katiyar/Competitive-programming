#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  string s;
  cin >> s;
  int n = static_cast<int> (s.size());
  int ans = -1;
  int cnt0 = count (s.begin(), s.end(), '0');
  int cnt1 = count (s.begin(), s.end(), '1');
  int diff = abs (cnt0 - cnt1);
  if (n % 2 == 0 && diff % 2 == 0 && cnt0 != n && cnt1 != n) { 
   ans = diff / 2;
  }
  cout << ans << '\n';
 }
 return 0;
}
