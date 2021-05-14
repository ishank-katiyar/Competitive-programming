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
  string a, b;
  cin >> a >> b;

  if (a == b) {
   cout << "YES" << '\n';
   continue;
  }

  auto check = [&] (int l, int r) -> bool {
   bool ok1 = true, ok2 = true;
   for (int i = l; i <= r; i++) {
    ok1 &= (a[i] == b[i]);
   }
   for (int i = l; i <= r; i++) {
    ok2 &= (a[i] != b[i]);
   }
   return ok1 || ok2;
  };

  auto check1 = [&] (int l, int r) -> bool {
   bool ok1 = true;
   for (int i = l; i <= r; i++) {
    ok1 &= (a[i] == b[i]);
   }
   return ok1;
  };

  int prev = 0;

  int cnt0 = 0, cnt1 = 0;

  bool ok = true;

  for (int i = 0; i < n; i++) {
   if (a[i] == '0') {
    cnt0 += 1;
   } else {
    cnt1 += 1;
   }

   if (cnt0 == cnt1) {
    ok &= check (prev, i);
    prev = i + 1;
   }
  }

  // if (prev == 0) {
  //  ok = false;
  // }

  ok &= check1 (prev, n - 1);

  cout << (ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
