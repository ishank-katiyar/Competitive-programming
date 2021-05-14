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

const int maxn = 1e5 + 1;
vector<multiset<int>> adj(maxn);
vector<int> w(maxn);
map<pair<int , int>  , queue<int>> mp;
vector<int> deg(maxn , 0);
set<pair<int , int> , greater<pair<int , int>>> s;
map<int , bool> mp2;
vector<int> ans;

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 int n , m;
 cin >> n >> m;
 for(int i = 1; i <= n; i++) cin >> w[i];
 for(int i = 1; i <= m; i++) {
  int x , y;
  cin >> x >> y;
  if(x > y) swap(x , y);
  mp[make_pair(x , y)].push(i);
  deg[x]++;
  deg[y]++;
  adj[x].insert(y);
  adj[y].insert(x);
 }
 for(int i = 1; i <= n; i++) {
  s.insert(make_pair(w[i] - deg[i] , i));
 }
 while(s.empty() == false) {
  pair<int , int> pp = *s.begin();
  s.erase(s.begin());
  if(pp.first < 0) break;
  int u = pp.second;
  for(int v : adj[u]) {
   if(mp2.count(v)) continue;
   pair<int , int> cur = make_pair(w[v] - deg[v] , v);
   assert(s.count(cur) == 1);
   s.erase(cur);
   deg[v]--;
   s.insert(make_pair(w[v] - deg[v] , v));
   pair<int ,int> cc = make_pair(min(u , v) , max(u , v));
   ans.emplace_back(mp[cc].front());
   mp[cc].pop();
  }
  mp2[u] = true;
 }
 if((int) ans.size() != m) {
  debug(ans);
  cout << "DEAD" << '\n';
  return 0;
 }
 reverse(ans.begin() , ans.end());
 cout << "ALIVE" << '\n';
 for(int i : ans) cout << i << ' ';
 cout << '\n';
 return 0;
}
