#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 const int maxn = 500;
 int t;
 cin >> t;
 while (t--) {
  string a, b;
  cin >> a >> b;
  auto f = [] (string A, string B) -> bool {
   int sza = static_cast <int> (A.size());
   int szb = static_cast <int> (B.size());
   if (sza % szb) return false;
   int x = sza / szb;
   string aa = "";
   while (x--) aa += B;
   return A == aa;
  };
  string aa = "";
  string ans = "-1";
  while (static_cast <int> (aa.size()) <= maxn) {
   aa += a;
   if (f (aa, b))  {
    ans = aa;
    break;
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
