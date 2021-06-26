#ifdef LOCAL
 #include <P.hpp>
 #include <debugger.hpp>
 #define __int64 __int64_t
#else 
 #include <bits/stdc++.h>
 #define debug(a...) //
 // #define __int64 long long int
#endif
using namespace std;

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 int n;
 cin >> n;
 vector<int> a(n);
 for(int i = 0; i < n; i++) cin >> a[i];
 set<int> s;
 int prev = -1;
 vector<pair<int ,int>> ans;
 for(int i = 0; i < n; i++) {
  if(s.count(a[i])) {
   if(prev == -1) prev = 0;
   ans.emplace_back(prev , i);
   prev = i + 1;
   s.clear();
  } 
  else {
   s.insert(a[i]);
  }
 }
 if(ans.size() == 0) cout << -1 << '\n';
 else {
  pair<int,  int> p = ans.back();
  ans.pop_back();
  ans.emplace_back(p.first , n - 1);
  cout << ans.size() << '\n';
  for(auto& i : ans) cout << i.first + 1 << ' ' << i.second + 1 << '\n';
 }
 return 0;
}
