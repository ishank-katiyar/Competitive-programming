#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int test_case = 0;
 cin >> test_case;
 for (int ttt = 1; ttt <= test_case; ttt++) {
  cout << "Case #" << ttt << ": ";
  long long l, r;
  cin >> l >> r;
  auto f = [] (long long n) -> bool {
   string S = to_string (n);
   int sz = (int) S.size();
   for (int i = 1; i <= sz; i++) {
    int dd = int (S[i - 1] - '0');
    if (dd % 2 != i % 2) return false;
   }
   return true;
  };
  long long ans = 0;
  for (long long i = l; i <= r; i++) {
   if (f (i)) ans++;
  }
  cout << ans << '\n';
 }
 return 0;
}
