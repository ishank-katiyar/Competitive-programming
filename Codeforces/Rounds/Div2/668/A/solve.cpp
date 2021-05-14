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
  vector<int> a(n);
  for(auto& i: a) cin >> i;
  reverse(a.begin(), a.end());
  for(auto i: a) cout << i << ' ';
  cout << '\n';
 }
 return 0;
}
