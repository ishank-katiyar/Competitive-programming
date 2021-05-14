#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  multiset<int> a;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   a.insert(x);
  }
  vector<int> ans;
  int c = *(--a.end());
  a.erase(--a.end());
  ans.push_back(c);
  while (a.empty() == false) {
   int mx = 0;
   int aa = -1;
   for (auto i: a) {
    int cc = __gcd(i, c);
    if (cc > mx) {
     mx = cc;
     aa = i; 
    }
   }
   ans.push_back(aa);
   c = __gcd(c, aa);
   a.erase(a.find(aa));
  }
  assert ((int) ans.size() == n);
  for (auto& i: ans) cout << i << ' ';
  cout << '\n';
 }
 return 0;
}
