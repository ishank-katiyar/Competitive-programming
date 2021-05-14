#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 long long w;
 cin >> w;
 const int maxa = 2e5 + 1;
 vector<long long> c (maxa, 0);
 while (n--) {
  long long s, t, p;
  cin >> s >> t >> p;
  c[s] += p;
  c[t] -= p;
 }
 long long sum = 0;
 for (int i = 0; i < maxa; i++) {
  sum += c[i];
  if (sum > w) {
   cout << "No" << '\n';
   return 0;
  }
 }
 cout << "Yes" << '\n';
 return 0;
}
