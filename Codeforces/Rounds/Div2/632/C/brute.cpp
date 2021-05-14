#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int64_t n;
 cin >> n;
 vector<int64_t> a (n);
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }

 auto f = [] (const vector <int64_t> A) -> bool {
  assert (A.empty() == false);
  int sz = static_cast <int> (A.size());
  for (int i = 0; i < sz; i++) {
   int64_t sum = 0;
   for (int j = i; j < sz; j++) {
    sum += A[j];
    if (sum == 0) {
     return false;
    }
   }
  }
  return true;
 };

 int64_t ans = 0;

 for (int i = 0; i < n; i++) {
  vector<int64_t> aa;
  for (int j = i; j < n; j++) {
   aa.push_back (a[j]);
   ans += f (aa);
  }
 }

 cout << ans << '\n';

 return 0;
}
