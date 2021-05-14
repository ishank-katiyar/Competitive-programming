#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 long long int l, r;
 cin >> l >> r;
 long long int k;
 cin >> k;
 vector<long long int> a;
 long long int x = 1;
 while (x <= r) {
  a.push_back(x);
  long double X = x, K = k;
  if (X * K > 1e18) break;
  x *= k;
 }  
 reverse (a.begin(), a.end());
 while (a.empty() == false && (a.back() > r || a.back() < l)) a.pop_back();
 reverse(a.begin(), a.end());
 if (a.empty() == true) cout << -1;
 else for (auto& i: a) cout << i << ' ';
 cout << '\n';
 return 0;
}
