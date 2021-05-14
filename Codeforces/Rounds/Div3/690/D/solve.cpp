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
  int ans = n - 1;

  auto f = [] (vector<int> A, int sum) -> int {
   int N = (int) A.size();
   reverse (A.begin(), A.end());
   int Ans = 0;
   while (A.empty() == false) {
    int cur_sum = 0;
    int ope = 0;
    while (A.empty() == false && cur_sum < sum) {
     cur_sum += A.back();
     A.pop_back();
     ope++;
    }
    if (cur_sum != sum) return N;
    Ans += ope - 1;
   }
   return Ans;
  };

  int sum = 0;
  for (int i = 0; i < n; i++) {
   sum += a[i];
   ans = min (ans, f (a, sum));
  }
  cout << ans << '\n';
 }
 return 0;
}
