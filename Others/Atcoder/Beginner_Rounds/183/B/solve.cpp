#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 long double a, b, c, d;
 cin >> a >> b >> c >> d;
 long double ans = (a * d + b * c) / (b + d);
 cout << fixed << setprecision(10) << ans << '\n';
 return 0;
}
