#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  string a, b;
  cin >> a >> b;
  vector<int> A(27), B(27);
  for (auto& i: a) {
   A[i - 'a']++;
  }
  for (auto& i: b) {
   B[i - 'a']++;
  }
  bool ok = true;
  for (int i = 0; i < 26; i++) {
   if (A[i] == B[i]) {
    continue;
   }
   if (A[i] < B[i]) {
    ok = false;
    break;
   }
   if (i < 25 && (A[i] - B[i]) % k == 0) {
    int cnt = A[i] - B[i];
    A[i] -= cnt;
    A[i + 1] += cnt;
   }
   else {
    ok = false;
    break;
   }
  }
  cout << (ok ? "Yes" : "No") << '\n';
 }
 return 0;
}
