#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  vector<int> n (3);
  cin >> n[0] >> n [1] >> n[2];
  vector <vector<int64_t>> a (3);
  for (int i = 0; i < 3; i++) {
   for (int j = 0; j < n[i]; j++) {
    int x;
    cin >> x;
    a[i].push_back (x);
   }
  }

  int64_t ans = LLONG_MAX;

  auto f = [&] (int64_t x, int64_t y, int64_t z) {
   ans = min (ans, (x - y) * (x - y) + (y - z) * (y - z) + (x - z) * (x - z));
  };

  auto ff = [&] (vector <int64_t> a1, vector<int64_t> a2, vector<int64_t> a3) {
   sort (a1.begin(), a1.end());
   sort (a2.begin(), a2.end());
   sort (a3.begin(), a3.end());
   int sz2 = static_cast <int> (a2.size());
   for (int i = 0; i < sz2; i++) {
    int64_t y = a2[i];
    auto it1 = lower_bound (a1.begin(), a1.end(), y);
    if (it1 == a1.begin() && *it1 != y) {
     continue;
    }
    if (it1 == a1.end() || *it1 != y) {
     it1--;
    }
    int64_t x = *it1;
    auto it3 = lower_bound (a3.begin(), a3.end(), y);
    if (it3 == a3.end()) {
     continue;
    }
    int64_t z = *it3;
    f (x, y, z);
   }
  };

  sort (a.begin(), a.end());

  do {
   ff (a[0], a[1], a[2]);
  } while (next_permutation (a.begin(), a.end()));

  cout << ans << '\n';
 }
 return 0;
}
