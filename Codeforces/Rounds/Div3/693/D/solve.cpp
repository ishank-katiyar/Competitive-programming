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
  vector<int> odd, even;
  for (int i = 0; i < n; i++) {
   cin >> a[i];
   if (a[i] % 2 == 1) odd.push_back (a[i]);
   else even.push_back (a[i]);
  }
  sort (odd.begin(), odd.end());
  sort (even.begin(), even.end());
  bool ok = true;
  int64_t B = 0, A = 0;
  while (odd.empty() == false && even.empty() == false) {
   if (odd.back() >= even.back()) {
    if (ok) {
     A += 0;
    } else {
     B += odd.back();
    }
    odd.pop_back();
   } else {
    if (ok) {
     A += even.back();
    } else {
     B += 0;
    }
    even.pop_back();
   }
   ok ^= 1;
  }
  while (odd.empty() == false) {
   if (ok) {
    A += 0;
   } else {
    B += odd.back();
   }
   odd.pop_back();
   ok ^= 1;
  }
  while (even.empty() == false) {
   if (ok) {
    A += even.back();
   } else {
    B += 0;
   }
   even.pop_back();
   ok ^= 1;
  }
  if (A == B) cout << "Tie" << '\n';
  else cout << (A > B ? "Alice" : "Bob") << '\n';
 }
 return 0;
}
