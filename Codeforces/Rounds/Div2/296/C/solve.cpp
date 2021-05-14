#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int w, h, n;
 cin >> w >> h >> n;
 set<int> H;
 H.insert(0);
 H.insert(h);
 set<int> W;
 W.insert(0);
 W.insert(w);
 multiset<long long int> len_H, len_W;
 len_H.insert(h);
 len_W.insert(w);
 for (int i = 0; i < n; i++) {
  char ch;
  cin >> ch;
  if (ch == 'H') {
   int y;
   cin >> y;
   auto it = H.lower_bound(y);
   assert (it != H.begin());
   it--;
   int l = *it;
   it = H.upper_bound(y);
   assert (it != H.end());
   int r = *it;
   H.insert(y);
   len_H.erase(len_H.find(r - l));
   int len1 = y - l;
   int len2 = r - y;
   len_H.insert(len1);
   len_H.insert(len2);
  }
  else {
   int x;
   cin >> x;
   auto it = W.lower_bound(x);
   assert (it != W.begin());
   it--;
   int l = *it;
   it = W.upper_bound(x);
   assert (it != W.end());
   int r = *it;
   W.insert(x);
   len_W.erase(len_W.find(r - l));
   int len1 = x - l;
   int len2 = r - x;
   len_W.insert(len1);
   len_W.insert(len2);
  }
  long long int ans = *(--len_H.end()) * *(--len_W.end());
  cout << ans << '\n';
 }
 return 0;
}
