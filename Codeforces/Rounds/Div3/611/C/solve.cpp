#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 set<int> s;
 for (int i = 1; i <=n; i++) s.insert(i);
 vector<int> a(n);
 int idx = -1;
 int c = 1; 
 for (auto& i: a) {
  cin >> i;
  if (i != 0) s.erase(i);
  else idx = c;
  c++;
 }
 if (idx == *(s.begin())) {
  for (int i = 0; i < n; i++) {
   if (a[i] == 0) {
    a[i] = idx;
    assert (i + 1 != idx);
    s.erase(s.begin());
    break;
   }
  }
 }
 for (int i = 0; i < n; i++) {
  if (a[i] == 0) {
   assert (s.empty() == false);
   auto it = s.end();
   it--;
   int x = *it;
   s.erase(it);
   if (x == i + 1) {
    assert (s.empty() == false);
    int y = *(--s.end());
    s.erase(--s.end());
    a[i] = y;
    s.insert(x);
   } 
   else {
    a[i] = x;
   }
  }
 }
 for (auto& i: a) cout << i << ' ';
 cout << '\n';
 return 0;
}
