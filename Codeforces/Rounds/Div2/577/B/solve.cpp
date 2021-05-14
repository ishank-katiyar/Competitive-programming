#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 multiset<pair<long long int, int>> a;
 vector<long long int> b(n);
 long long int sum = 0;
 for(int i = 0; i < n; i++) {
  int x;
  cin >> x;
  sum += x;
  b[i] = x;
  a.insert(make_pair(x, i));
 }
 int idx1 = (*(--a.end())).second;
 if(sum % 2 == 1) {
  cout << "NO\n";
  return 0;
 }
 bool ok = false;
 while(1) {
  n = (int) a.size();
  long long int mx = (*(--a.end())).first;
  int idx = (*(--a.end())).second;
  if(n == 1) {
   //cout << mx << '\n';
   //cout << idx << '\n';
   ok = (mx <= (sum - b[idx])) && (idx != idx1);
   break;
  }
  long long int mn = (*a.begin()).first;
  a.erase(a.begin());
  a.erase(--a.end());
  mx -= mn;
  if(mx == 0) {
   ok = true;
   break;
  }
  if(mx > 0) a.insert(make_pair(mx, idx));
 }
 cout << (ok ? "YES" : "NO") << '\n';
 return 0;
}
