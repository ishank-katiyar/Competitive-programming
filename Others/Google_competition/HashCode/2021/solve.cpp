#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd() {
 return uniform_int_distribution<int> (1, static_cast <int> (1e9)) (rng);
}

template<class A> 
A rnd(A x, A y) {
 return uniform_int_distribution<A> (x, y) (rng);
}

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int simulationtime, n, m, nocars, F;
 cin >> simulationtime >> n >> m >> nocars >> F;
 vector<vector<pair<int, int>>> adj (n);
 vector<string> streetname(m);
 map <string, pair<int, int>> streetinfo;
 // vector<vector<string>> IN(n), OUT(n);
 vector<vector<pair<string, int>>> IN(n), OUT(n);
 for (int i = 0; i < m; i++) {
  int S, E;
  cin >> S >> E;
  cin >> streetname[i];
  streetinfo[streetname[i]] = make_pair(S, E);
  // IN[E].push_back (streetname[i]);
  // OUT[S].push_back (streetname[i]);
  IN[E].emplace_back (streetname[i], 0);
  OUT[S].emplace_back (streetname[i], 0);
  int L;
  cin >> L;
  adj[S].emplace_back (E, L);
 }
 vector<vector<string>> pathcar(nocars);
 for (int i = 0; i < nocars; i++) {
  int sz;
  cin >> sz;
  for (int j = 0; j < sz; j++) {
   string S;
   cin >> S;
   pathcar[i].push_back (S);
   if (j == 0) {
    int ending = streetinfo[S].second;
    for (auto& I: IN[ending]) {
     if (I.first == S) {
      I.second += 1;
      break;
     }
    }
   }
  }
 }
 cout << n << '\n';
 for (int i = 0; i < n; i++) {
  cout << i << '\n';
  cout << static_cast <int> (IN[i].size()) << '\n';
  // int expected_time = INT_MAX;
  // for (auto& I: adj[i]) {
  //  expected_time = min (expected_time, I.second);
  // }
  sort (IN[i].begin(), IN[i].end(), [] (const pair <string, int> A, const pair <string, int> B) -> bool {
   if (A.second != B.second) return A.second > B.second;
   return A.first < B.first;
  });
  reverse (IN[i].begin(), IN[i].end());
  for (auto& I: IN[i]) {
   // cout << I.first << ' ' << min (simulationtime, max (1, I.second)) << '\n';
   cout << I.first << ' ' << rnd (1, 1) << '\n';
   // cout << I << ' ' << 1 << '\n';
   // cout << I << ' ' << expected_time << '\n';
  }
 }
 return 0;
}
