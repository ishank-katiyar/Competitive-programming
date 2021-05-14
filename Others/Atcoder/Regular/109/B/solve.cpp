#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 long long n;
 cin >> n;
 long long N = n + 1;
 long long x = 1;
 long long cnt = 0;
 while (N >= x) {
  N -= x;
  x++;
  cnt++;
 }
 cout << n - cnt + 1 << '\n';
 return 0;
}
