#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 const int MAXN = static_cast <int> (1e5 + 1);
 int log[MAXN+1];
 log[1] = 0;
 for (int i = 2; i <= MAXN; i++)
     log[i] = log[i/2] + 1;
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> A (n);
  for (int i = 0; i < n; i++) {
   cin >> A[i];
  }

  vector<int> ans (n);

  auto f = [&] (const vector<int> a) {
   int N = static_cast <int> (a.size());

   const int K = 25;

   int st[N + 1][K + 1];

   for (int i = 0; i < N; i++)
       st[i][0] = a[i];

   for (int j = 1; j <= K; j++)
       for (int i = 0; i + (1 << j) <= N; i++)
           st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);


   map <int, vector<int>> mp;

   for (int i = 0; i < n; i++) {
    mp[a[i]].push_back (i);
   }

   auto ff = [&] (int X, int I, int J) -> int {
    int ret = upper_bound (mp[X].begin(), mp[X].end(), J) - lower_bound (mp[X].begin(), mp[X].end(), I);
    return ret;
   };

   for (int i = 0; i < n; i++) {
    int low = 0, high = i;
    while (low < high) {
     int mid = (low + high) / 2;
     int j = log[i - mid + 1];
     int maxi = max (st[mid][j], st[i - (1 << j) + 1][j]);
     if (maxi > a[i]) {
      low = mid + 1;
     } else {
      high = mid;
     }
    }
    ans[i] += ff (a[i], low, i);
   }
  };

  f (A);
  reverse (A.begin(), A.end());
  reverse (ans.begin(), ans.end());
  f (A);
  reverse (ans.begin(), ans.end());
  for (auto& i: ans) {
   cout << i - 2 << ' ';
  }
  cout << '\n';
 }
 return 0;
}
