#include <bits/stdc++.h>

using namespace std;

int main() 
{
 int n;
 cin >> n;

 vector<int> a (n + 1, -1);

 auto ask = [&] (int index) -> int {
  if (a[index] != -1) {
   return a[index]; 
  }
  cout << "? " << index << endl;
  int value;
  cin >> value;
  a[index] = value;
  return value;
 };

 int ans = -1;

 int low = 1, high = n;

 while (low < high) {
  int mid = (low + high) / 2;
  int f = n + 1, s = ask (mid), t = n + 1;
  if (mid - 1 >= 1) f = ask (mid - 1);
  if (mid + 1 <= n) t = ask (mid + 1);
  if (s < f && s < t) {
   ans = mid;
   break;
  }
  if (f < s && s < t) {
   high = mid; 
  } else if (f > s && s > t) {
   low = mid + 1;
  } else {
   // low = mid + 1;
   high = mid;
  }
 }

 if (ans == -1) {
  ans = low;
 }

 cout << "! " << ans << '\n';

 return 0;
}
