#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 vector<pair<int, int>> a(n);
 for (int i = 0; i < n; i++) {
  cin >> a[i].first;
  a[i].second = i + 1;
 }
 sort (a.begin(), a.end());
 vector<int> A, B;
 for (int i = 0; i < n; i++) {
  if (i % 2 == 0) A.push_back(a[i].second);
  else B.push_back(a[i].second);
 }
 cout << (int) A.size() << '\n';
 for (auto& i: A) cout << i << ' ';
 cout << '\n';
 cout << (int) B.size() << '\n';
 for (auto& i: B) cout << i << ' ';
 cout << '\n';
 return 0;
}
