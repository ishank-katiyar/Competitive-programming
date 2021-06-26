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

int ncr(int n) {
 return (n * (n - 1) * (n - 2)) / 6;
}

vector<vector<int>> adj(101);

void add_edge(int i , int j) {
 adj[i].emplace_back(j);
 adj[j].emplace_back(i);
}

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 int k;
 cin >> k;
 int startedge;
 for(int i = 3; i <= 101; i++) if(ncr(i) > k) {
  startedge = i - 1;
  break;
 }
 for(int i = 1; i <= startedge; i++) for(int j = i + 1; j <= startedge; j++) add_edge(i , j);
 k -= ncr(startedge);
 debug(startedge , k);
 while(k > 0) {
  int cur = 3;
  startedge++;
  debug(k , startedge);
  add_edge(startedge , 1);
  add_edge(startedge , 2);
  k--;
  while(k >= cur) {
   add_edge(startedge , cur);
   k -= cur - 1;
   cur++;
  }
 }
 /*
 for(int i = 1; i <= 100; i++) {
  debug(i);
  for(int j : adj[i]) cout << j << ' ';
  cout << '\n';
 }
 */
 vector<vector<bool>> ans(startedge + 1 , vector<bool>(startedge + 1, 0));
 for(int i = 1; i <= startedge; i++) {
  for(int j : adj[i]) {
   ans[i][j] = 1;
   ans[j][i] = 1;
  }
 }
 cout << startedge << '\n';
 for(int i = 1; i <= startedge; i++) {
  for(int j = 1; j <= startedge; j++) {
   cout << ans[i][j];
  }
  cout << '\n';
 } 
 return 0;
}
