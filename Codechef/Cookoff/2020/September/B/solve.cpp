#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int N = count(s.begin(), s.end(), '0');
  if (k == 0) {
   cout << N << '\n';
   continue;
  }
  int left = 0, right = 0;
  while (s.empty() == false && s.back() == '0') s.pop_back(), right++;
  reverse(s.begin(), s.end());
  while (s.empty() == false && s.back() == '0') s.pop_back(), left++;
  reverse(s.begin(), s.end());
  vector<int> a;
  n = (int) s.size();
  int cur = 0;
  for (auto& i: s) {
   if (i == '1') {
    if (cur > 0) a.push_back(cur);
    cur = 0;
   }
   else cur++;
  }
  sort(a.rbegin(), a.rend());
  vector<int> pre(k + 1);
  pre[0] = 0;
  int sz = (int) a.size();
  int sum = 0;
  for (int i = 0; i < sz; i++) {
   int idx = 2 * (i + 1);
   sum += a[i];
   if (idx <= k) pre[idx] = sum;
  }
  int ans = 0;
  int ans1 = 0;
  int K1 = k;
  if (K1 % 2 == 1) K1--;
  ans1 = pre[K1];
  ans = max(ans, ans1);
  if (left > 0) {
   int ans2 = left;
   int k2 = k - 1;
   if (k2 % 2 == 1) k2--;
   ans2 += pre[k2];
   ans = max(ans, ans2); 
  }
  if (right > 0) {
   int ans3 = right;
   int k3 = k - 1;
   if (k3 % 2 == 1) k3--;
   ans3 += pre[k3];
   ans = max(ans, ans3);
  }
  if (left > 0 && right > 0 && k >= 2) {
   int ans4 = left + right;
   int k4 = k - 2;
   if (k4 % 2 == 1) k4--;
   ans4 += pre[k4];
   ans = max(ans, ans4);
  }
  cout << N - ans << '\n';
 }
 return 0;
}
