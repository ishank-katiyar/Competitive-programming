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
  int n;
  cin >> n;
  long long int sum = 0;
  long long int ans = 0;
  while(n--) {
   int x;
   cin >> x;
   sum += x;
   ans = min(ans, sum);
  }
  cout << -ans << '\n';
 }
 return 0;
}
