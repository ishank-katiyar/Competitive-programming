#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 int b, a;
 cin >> b >> a;
 int AA = a;
 vector<int> A(n);
 for (auto& i: A) cin >> i;
 for (int i = 0; i < n; i++) {
  if (a == 0 && b == 0) {
   cout << i << '\n';
   return 0;
  }
  if (A[i] == 1) {
   if (a == AA) {
    a--;
   } 
   else {
    if (b > 0) {
     a++, b--;
    }
    else a--;
   }
  }
  else {
   if (a > 0) a--;
   else b--;
  }
 }
 cout << n << '\n';
 return 0;
}
