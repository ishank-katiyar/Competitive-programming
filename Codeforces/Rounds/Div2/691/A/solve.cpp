#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < n; i++) {
   if (a[i] == b[i]) continue;
   if (a[i] > b[i]) cnt0++;
   else cnt1++;
  }
  if (cnt0 == cnt1) cout << "EQUAL" << '\n';
  else cout << (cnt0 > cnt1 ? "RED" : "BLUE") << '\n';
 }
 return 0;
}