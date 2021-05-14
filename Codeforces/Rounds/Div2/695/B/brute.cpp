#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  int mn = 0;
  int mx = *max_element (a.begin(), a.end()) + 2;
  int sum = 0;

  auto f = [&] (int i) -> bool {
   if (i <= 0 || i >= n - 1) return false;
   assert (i > 0 && i < n - 1);
   if (a[i] > a[i - 1] && a[i] > a[i + 1]) return true;
   if (a[i] < a[i - 1] && a[i] < a[i + 1]) return true;
   return false;
  };

  for (int i = 0; i < n; i++) {
   sum += f (i);
  }

  int ans = sum;

  for (int i = 0; i < n; i++) {
   int cur_ans = INT_MAX;
   int tem = a[i];

   for (a[i] = mn; a[i] <= mx; a[i]++) {
    int cur_ans1 = 0;
    for (int j = 0; j < n; j++) {
     cur_ans1 += f (j);
    }
    cur_ans = min (cur_ans, cur_ans1);
   }

   a[i] = tem;

   ans = min (ans, cur_ans);
  }
  cout << ans << '\n';
 }
 return 0;
}
