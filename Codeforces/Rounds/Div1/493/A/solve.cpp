#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 long long int x, y;
 cin >> x >> y;
 string s;
 cin >> s;
 vector<int> a;
 int cur = 0;
 for (int i = 0; i < n; i++) {
  if (s[i] == '1') {
   if (cur > 0) a.push_back(cur);
   cur = 0;
  }
  else cur++;
 }
 if (cur > 0) a.push_back(cur);
 int sz = (int) a.size();
 int Sz = sz;
 long long int ans = y * sz;
 int c = 0;
 while (sz > 1) {
  int X = a.back();
  a.pop_back();
  a.back() += X;
  sz--;
  c++;
  ans = min(ans, sz * y + c * x); 
 }
 assert (sz == 0 || c == Sz - 1);
 ans = min(ans, y + c * x);
 cout << ans << '\n';
 return 0;
}
