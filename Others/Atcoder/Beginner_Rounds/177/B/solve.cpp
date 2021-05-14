#include <bits/stdc++.h>
using namespace std;

int f(string a, string b) {
 int n = (int) a.size();
 int ans = 0;
 for(int i = 0; i < n; i++) {
  ans += (a[i] != b[i]);
 }
 return ans;
}

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 string a, b;
 cin >> a >> b;
 int n1 = (int) a.size();
 int n2 = (int) b.size();
 int ans = n2;
 for(int i = 0; i <= n1-n2; i++) {
  ans = min(ans, f(a.substr(i, n2), b));
 }
 cout << ans << '\n';
 return 0;
}
