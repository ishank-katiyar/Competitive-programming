#include <bits/stdc++.h>

using namespace std;

void solve() {
 int n, a, b, c;
 cin >> n >> a >> b >> c;
 if(c == 1 && n != 1) {
  if(a == 1 || b == 1) {
   if(a == 1 && b == 1) {
    cout << "IMPOSSIBLE\n";
    return;
   }
   vector<int> ans;
   if(a == 1) {
    ans.push_back(n);
    b--;
    int rem = n - 1 - b;
    if(rem < 0) {
     cout << "IMPOSSIBLE\n";
     return;
    }
    while(rem--) ans.push_back(1);
    while(b--) ans.push_back(n-1);
    assert((int) ans.size() == n);
    for(auto& i: ans) cout << i << ' ';
    cout << '\n';
    return;
   }
   else if(b == 1) {
    ans.push_back(n);
    a--;
    int rem = n - 1 - a;
    if(rem < 0) {
     cout << "IMPOSSIBLE\n";
     return;
    }
    while(rem--) ans.push_back(1);
    while(a--) ans.push_back(n-1);
    reverse(ans.begin(), ans.end());
    assert((int) ans.size() == n);
    for(auto& i: ans) cout << i << ' ';
    cout << '\n';
    return;
   }
  }
  else {
   a--;
   b--;
   int rem = n - (a + b + c);
   if(rem < 0) {
    cout << "IMPOSSIBLE\n";
    return;
   }
   vector<int> ans(a, n-1);
   while(rem--) ans.push_back(1);
   ans.push_back(n);
   while(b--) {
    ans.push_back(n-1);
   }
   for(auto& i: ans) cout << i << ' ';
   cout << '\n';
   return;
  }
 }
 vector<int> ans(c-1, n);
 a -= c;
 b -= c;
 int rem = n - (c + a + b);
 if(rem < 0) {
  cout << "IMPOSSIBLE\n";
  return;
 }
 while(rem--) ans.push_back(1);
 ans.push_back(n);
 reverse(ans.begin(), ans.end());
 while(a--) ans.push_back(n-1);
 reverse(ans.begin(), ans.end());
 while(b--) ans.push_back(n-1);
 assert((int) ans.size() == n);
 for(auto& i: ans) cout << i << ' ';
 cout << '\n';
}

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 for(int tt = 1; tt <= t; tt++) {
  cout << "Case #" << tt << ": ";
  solve();
 }
}
