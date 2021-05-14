#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
 #define __int64 __int64_t
#else 
 #define debug(a...) //
#endif

#define __int64 long long int

const int maxn = 2e5 + 1;
vector<vector<int>> adj(maxn);
vector<__int64> cost(maxn);
vector<__int64> population(maxn);
vector<bool> used(maxn);
vector<int> a;

void dfs(int n , int index) {
 if(used[n]) return;
 used[n] = true;
 for(int& i : adj[n]) {
  if(used[i]) continue;
  if(cost[i - 1] * population[index] > cost[index] * population[i - 1]) {
   debug(i , cost[i] , population[i]);
  }
  assert(cost[i - 1] * population[index] <= cost[index] * population[i - 1]);
  if(cost[index] * population[i - 1] == cost[i - 1] * population[index]) {
   a.emplace_back(i);
   dfs(i , index);
  }
 }
}

void solve() {
 for(int i = 0; i < maxn; i++) adj[i].clear() , cost[i] = 0 , population[i] = 0 , used[i] = false;
 a.clear();
 int n , m;
 cin >> n >> m;
 for(int i = 0; i < n; i++) cin >> cost[i];
 for(int i = 0; i < n; i++) cin >> population[i];
 int ans = 0;
 for(int i = 1; i < n; i++) {
  if(cost[i] * population[ans] > cost[ans] * population[i]) {
   ans = i;
  }
 }
 debug(ans , cost[ans] , population[ans]);
 vector<int> index;
 for(int i = 0; i < n; i++) {
  if(cost[i] * population[ans] == cost[ans] * population[i]) {
   index.emplace_back(i + 1);
  }
 }
 debug(index);
 for(int i = 0; i < m; i++) {
  int x , y;
  cin >> x >> y;
  adj[x].emplace_back(y);
  adj[y].emplace_back(x);
 }
 a.emplace_back(ans + 1);
 vector<int> best;
 for(int& i : index) {
  if(used[i] == false) {
   a.clear();
   a.emplace_back(i);
   dfs(i , ans);
   debug(a);
   if((int) a.size() > (int) best.size()) {
    best = a;
   }
  }
 }
 cout << (int) best.size() << '\n';
 for(int& i : best) cout << i << ' ';
 cout << '\n';
}

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) solve();
 return 0;
}
