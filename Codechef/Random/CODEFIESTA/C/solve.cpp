#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long cnt1 = 0, cnt0 = 0, ans = 0;
  for(char& ch: s) {
   if(ch == '0') ans += cnt1, cnt0++;
   else ans += cnt0, cnt1++;
  } 
  cout << ans << '\n';
 }
}
