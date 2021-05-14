#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 vector<pair<int, int>> a(n);
 int edge = 0;
 for (auto& i: a) {
  cin >> i.first >> i.second;
  edge += i.first;
 }
 assert (edge % 2 == 0);
 edge /= 2;
 assert (edge < n);
 vector<vector<int>> adj(n);
 vector<pair<int, int>> ans;
 queue<int> q;
 for (int i = 0; i < n; i++) {
  if (a[i].first == 1) q.push(i);
 }
 while (q.empty() == false) {
  int u = q.front();
  q.pop();
  //cerr << u << ' ' << a[u].first << '\n';
  if (a[u].first > 1) {
   q.push(u);
   continue;
  }
  assert (a[u].first <= 1 && a[u].first >= 0);
  if (a[u].first == 0) {
   continue;
  }
  a[u].first = 0;
  int v = a[u].second;
  ans.emplace_back(u, v);
  a[v].first--;
  a[v].second ^= u;
  assert (a[v].first >= 0);
  if (a[v].first > 0) q.push(v);
 }

 //for (auto& i: ans) cerr << i.first << ' ' << i.second << '\n';
 assert ((int) ans.size() == edge);
 cout << edge << '\n';
 for (auto& i: ans) cout << i.first << ' ' << i.second << '\n';
 return 0;
}
