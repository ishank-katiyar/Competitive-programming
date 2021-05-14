#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> aa(n);
  int d = -1;
  for(int i = 1; i <= 100; i++) {
   if((y - x) % i == 0) {
    if((y - x) / i < n) {
     d = i;
     break;
    }
   }
  }
  assert(d != -1);
  int a = y - (n-1) * d;
  while(a <= 0) a += d;
  for(int i = 0; i < n; i++) aa[i] = a + i * d;
  assert(aa[0] <= x && aa[n-1] >= y);
  for(auto& i: aa) cout << i << ' ';
  cout << '\n';
 }
 return 0;
}
