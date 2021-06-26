#include <bits/stdc++.h>

using namespace std;

vector<long long> brute(vector<long long> &a, vector<long long> &b) {
 int N = 1;
 int sz_sum = (int) a.size() + (int) b.size();
 while (N < sz_sum) N *= 2;
 vector<long long> ans(N);
 int n = (int) a.size();
 int m = (int) b.size();
 for (int i = 0; i < n; i++) {
  for (int j = 0; j < m; j++) {
   assert (i + j < N);
   ans[i + j] += a[i] * b[j];
  }
 }
 return ans;
}

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<long long> a(n); 
 for (auto& i: a) cin >> i;
 vector<long long> b(n); 
 for (auto& i: b) cin >> i;
 vector<long long> mul = brute(a, b);
 for (auto& i: mul) cout << i << ' ';
 cout << '\n';
 return 0;
}
