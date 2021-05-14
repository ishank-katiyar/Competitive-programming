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
 for (auto& i: a) cin >> i.first >> i.second;
 sort (a.begin(), a.end(), [] (const pair<int, int> A, const pair<int, int> B) -> bool {
  if (A.first == B.first) return A.second < B.second;
  return A.first < B.first;
 });
 int A = -1, B = -1;
 bool ok = true; 
 for (int i = 0; i < n; i++) {
  if (A >= a[i].first && B >= a[i].first) {
   ok = false;
   break;
  }
  if (A < a[i].first) {
   A = a[i].second;
   continue;
  }
  assert (B < a[i].first);
  B = a[i].second;
 }
 cout << (ok ? "YES" : "NO") << '\n';
 return 0;
}
