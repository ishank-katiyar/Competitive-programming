#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, x, t;
 cin >> n >> x >> t;
 int ans = 1;
 if(n % x) ans = n / x + 1;
 else ans = n / x;
 ans *= t;
 cout << ans << '\n';
}
