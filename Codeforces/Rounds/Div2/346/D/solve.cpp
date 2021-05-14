#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;

 auto check = [&] (int x, int y, int x1, int y1, int x2, int y2) -> bool {
  pair<int, int> p1 = make_pair(x1 - x, y1 - y);
  pair<int, int> p2 = make_pair(x2 - x1, y2 - y1);
  int ret = p1.first * p2.second - p1.second * p2.first;
  return ret < 0;
 };

 n++;
 vector<pair<int, int>> a(n);
 for (auto& i: a) cin >> i.first >> i.second;
 int ans = 0;
 for (int i = 0; i < n; i++) {
  if (i > 1) {
   ans += check(a[i].first, a[i].second, a[i -  1].first, a[i - 1].second, a[i - 2].first, a[i - 2].second); 
  }
 }
 cout << ans << '\n';
 return 0;
}


//0i + 1j
//1i + 0j
//-1k

//1i + 0j
//0j + 1j

