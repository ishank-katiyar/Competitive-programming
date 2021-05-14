#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n; 
 cin >> n;
 long double W;
 cin >> W;
 vector<int> a(2 * n);
 for (auto& i: a) cin >> i;
 sort (a.begin(), a.end());
 long double x = min((long double) a[0], (long double) a[n] / 2);
 x *= 3 * n;
 cout << fixed << setprecision(6) << min (x, W) << '\n';
 return 0;
}
