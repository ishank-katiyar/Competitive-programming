#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n, m;
 cin >> n >> m;
 vector<int> a (n);
 vector<int> b (m);
 for (int i = 0; i < n; i++) { 
  cin >> a[i];
 }
 for (int i = 0; i < m; i++) {
  cin >> b[i];
 }
 sort (a.begin(), a.end());
 sort (b.begin(), b.end());
 cout << (long long)(lower_bound(b.begin(), b.end(), a[0]) - b.begin()) * (long long)n << '\n';
 return 0;
}