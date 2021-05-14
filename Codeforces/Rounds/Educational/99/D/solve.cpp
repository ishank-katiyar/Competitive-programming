#include <bits/stdc++.h>

using namespace std;

bool is_sorted (vector<int> a) {
 vector<int> b (a);
 sort (b.begin(), b.end());
 return a == b;
}

int solve (vector<int> a, int x, int n, int ans) {
 if (is_sorted(a)) return ans;
 int upper_bound = -1;
 for (int i = 0; i < n; i++) {
  if (a[i] > x) {
   swap (a[i], x);
   ans++;
   upper_bound = i;
   break;
  }
 }
 if (upper_bound == -1) return -1;
 return solve (a, x, n, ans);
}

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, x;
  cin >> n >> x;
  vector<int> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  cout << solve (a, x, n, 0) << '\n';
 }
 return 0;
}
