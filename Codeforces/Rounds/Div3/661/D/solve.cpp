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
  string s;
  cin >> s;
  n = (int) s.size();
  set<int> s1, s2;
  for(int i = 0; i < n; i++) {
   if(s[i] == '0') s1.insert(i);
   else s2.insert(i);
  }
  int c = 1;
  vector<int> ans(n);
  while(s1.empty() == false && s2.empty() == false) {
   bool ok = true;
   int x = -1;
   if(*s1.begin() < *s2.begin()) ok = true, x = *s1.begin() - 1; 
   else ok = false, x = *s2.begin() - 1;
   while(1) {
    if(ok) {
     auto it = s1.upper_bound(x);
     if(it == s1.end()) break;
     assert(*it >= 0 && *it < n);
     ans[*it] = c;
     x = *it;
     s1.erase(it);
     ok = false;
    }
    else {
     auto it = s2.upper_bound(x);
     if(it == s2.end()) break;
     assert(*it >= 0 && *it < n);
     ans[*it] = c;
     x = *it;
     s2.erase(it);
     ok = true;
    }
   }
   c++;
  }
  while(s1.empty() == false) {
   auto it = s1.end();
   --it;
   assert(*it >= 0 && *it < n);
   ans[*it] = c++;
   s1.erase(it);
  }
  while(s2.empty() == false) {
   auto it = s2.end();
   --it;
   assert(*it >= 0 && *it < n);
   ans[*it] = c++;
   s2.erase(it);
  }
  cout << c - 1 << '\n';
  for(auto& i: ans) cout << i << ' ';
  cout << '\n';
 }
 return 0;
}
