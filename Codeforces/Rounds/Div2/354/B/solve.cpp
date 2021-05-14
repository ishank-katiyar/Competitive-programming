#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 int t;
 cin >> t;
 vector<int> a(((n * (n + 1)) / 2) + 1, 0);
 int sz = (int) a.size();
 const int maxa = 2048;
 
 auto f = [&] (int N) -> int {
  int x = 1;
  int sum = 0;
  while (sum < N) {
   sum += x++;
  }
  x--;
  sum -= x; 
  int A = N - sum;
  sum += x;
  return sum + A;
 };

 function<void(int)> get = [&] (int I) {
  if (a[I] > maxa) {
   int extra = a[I] - maxa;
   a[I] -= extra;
   assert (extra % 2 == 0);
   extra /= 2;
   int idx = f(I);
   if (idx < sz) a[idx] += extra;
   if (idx + 1 < sz) a[idx + 1] += extra;
   if (idx < sz) get (idx);
   if (idx + 1 < sz) get (idx + 1);
  }
  else {
   return;
  }
 };
 while (t--) {
  a[1] += maxa;
  get (1);
 }
 int cnt = 0;
 for (int i = 1; i < (int) a.size(); i++) {
  if (a[i] == maxa) cnt++;
 }
 cout << cnt << '\n';
 return 0;
}
