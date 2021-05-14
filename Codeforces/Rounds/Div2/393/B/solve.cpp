#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n, m, k;
 cin >> n >> m >> k;

 auto f = [&] (long long int mid, long long M) -> bool {
  if (mid > M) return false;
  M -= mid;
  long long left = max (mid - k + 1, 1LL);
  left--;
  left = (left * (left + 1)) / 2;
  long long L = (mid * (mid - 1)) / 2;
  assert (L >= left);
  L -= left;
  L += max (0LL, k - mid);
  //cerr << "L: " << L << endl;
  if (M < L) return false;
  M -= L;
  long long right = max (mid - (n - k), 1LL);
  right--;
  right = (right * (right + 1)) / 2;
  long long R = (mid * (mid - 1)) / 2;
  assert (R >= right);
  R -= right;
  R += max (0LL, n - k + 1 - mid);
  //cerr << "R: " << R << endl;
  if (M < R) return false;
  return true;
 };

 long long int low = m / n, high = m;
 while (low < high) {
  long long int mid = (low + high) / 2;
  //cerr << "mid: " << mid << endl;
  if (f(mid, m) == false) high = mid;
  else low = mid + 1;
 }
 if (f(low, m) == false) low--;
 assert (f(low, m) == true);
 cout << low << '\n';
 return 0;
}
/*
 * mid - 1, mid - 2, mid - 3, ... , max (mid - k + 1, 1);
 * 5 4 3
 * mid = 5
 * k = 3
 * 5, ... , 3
 * mid - 1, mid - 2, mid - 3, ... , max (mid - (n - k), 1);
 *
 */
