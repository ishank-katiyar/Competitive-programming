#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<int> a(n);
 for(auto& i: a) cin >> i;
 vector<int> dp;
 for(int i = 0; i < n; i++) {
  auto x = lower_bound(dp.begin(), dp.end(), a[i]);
  if(x == dp.end()) dp.push_back(a[i]);
  else *x = a[i];
 }
 cout << (int) dp.size() << '\n';
 return 0;
}
