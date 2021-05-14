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
  vector<int> a (n, -1);
  vector<int> b (n);
  for (int i = 0; i < n; i++) {
   cin >> b[i];
   if (i == 0) {
    a[i] = b[i];
   } else {
    if (b[i] != b[i - 1]) {
     a[i] = b[i];
    }
   }
  }
  set<int> s;
  for (int i = 1; i <= n; i++) {
   s.insert (i);
  }
  for (int i = 0; i < n; i++) {
   if (a[i] == -1) {
    cout << *(s.begin()) << ' ';
    s.erase (s.begin());
   } else {
    cout << a[i] << ' ';
    s.erase (a[i]);
   }
  }
  cout << '\n';
  assert (s.empty() == true);
  vector<bool> used (n + 1, false);
  for (int i = 0; i < n; i++) {
   if (a[i] == -1) {
    assert (s.empty() == false);
    cout << *(--s.end()) << ' ';
    s.erase (--s.end());
   } else {
    for (int j = a[i] - 1; used[j] == false && j > 0; j--) {
     s.insert (j);
     used[j] = true;
    }
    used[a[i]] = true;
    cout << a[i] << ' ';
   }
  }
  cout << '\n';
 }
 return 0;
}
