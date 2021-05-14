#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 vector<pair<int, int>> a(n);
 int sum = 0;
 for (int i = 0; i < n; i++) {
  cin >> a[i].first;
  a[i].second = i;
  sum += a[i].first;
 }
 int x = sum / n;
 sort (a.begin(), a.end());
 vector<pair<int, int>> b(a);
 int sum1 = sum;
 int idx = 0;
 int sum2 = 0;
 for (int i = 0; i < n; i++) {
  if (sum1 % (n - i) == 0) {
   x = sum1 / (n - i);
   idx = i;
   break;
  }
  else {
   b[i].first = x;
   sum1 -= x;
   sum2 += x;
  }
 }
 for (int i = idx; i < n; i++) b[i].first = x, sum2 += x;
 assert (sum2 == sum);
 sort (b.begin(), b.end(), [] (const pair<int, int> A, const pair<int, int> B) -> bool {
  return A.second < B.second;
 });
 sort (a.begin(), a.end(), [] (const pair<int, int> A, const pair<int, int> B) -> bool {
  return A.second < B.second;
 });
 //for (auto& i: a) cerr << i.first << ' ';
 //cerr << endl;
 //for (auto& i: b) cerr << i.first << ' ';
 //cerr << endl;

 int ans = 0;
 for (int i = 0; i < n; i++) ans += abs(a[i].first - b[i].first);
 assert (ans % 2 == 0);
 cout << ans / 2 << '\n';
 return 0;
}
