#include <bits/stdc++.h>

using namespace std;

int main() 
{
 map <pair<int, int>, int> mp;

 auto ask = [&] (int l, int r) -> int {
  if (mp.count (make_pair(l, r))) {
   return mp[make_pair(l, r)];
  }
  cout << "? " << l << ' ' << r << endl;
  int x;
  cin >> x;
  mp[make_pair(l, r)] = x;
  return x;
 };

 int n;
 cin >> n;

 int low = 1, high = n;

 int ans = -1;

 auto handletwo = [&] (int l, int r) {
  assert (r - l + 1 == 2);
  int X = ask (l, r);
  cout << "! " << l + r - X  << endl;
  exit(0);
 };

 while (low < high) {

  if (high - low + 1 == 2) {
   handletwo (low, high);
  }

  if (high - low + 1 == 3) {
   int dd = ask (low, high);
   if (dd == low) {
    handletwo(low + 1, high);
   }
   if (dd == high) {
    handletwo (low, low + 1);
   }
   int dd1 = ask (low + 1, high);
   if (dd1 == low + 1) {
    ans = high;
   } else {
    ans = low;
   }
   break;
  }

  int idx = ask (low, high);
  
  int mid = (low + high) / 2;

  mid += 1;
  
  if (idx < mid) {
   assert (mid - 1 - low + 1 >= 2);
   int idx1 = ask (low, mid - 1);
   if (idx == idx1) {
    high = mid - 1;
   } else {
    low = mid;
   }
  } else {
   assert (high - mid + 1 >= 2);
   int idx1 = ask (mid, high);
   if (idx == idx1) {
    low = mid;
   } else {
    high = mid - 1;
   }
  }
 }

 if (ans == -1) {
  ans = low;
 }

 cout << "! " << ans << endl;
 return 0;
}
