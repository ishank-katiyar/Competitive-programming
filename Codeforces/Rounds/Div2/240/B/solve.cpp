#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 long long int a, b;
 cin >> a >> b;
 vector<long long int> A(n);
 for (int i = 0; i < n; i++) {
  cin >> A[i];
  long long int x = (A[i] * a) % b;
  x /= a;
  cout << x << ' ';
 }
 cout << '\n';
 return 0;
}
