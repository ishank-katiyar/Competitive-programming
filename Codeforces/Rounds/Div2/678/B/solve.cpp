#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 1;
vector<int> prime;
vector<bool> is (maxn, true);

void seive () {
 is[0] = is[1] = false;
 for (int i = 2; i < maxn; i++) {
  if (is[i]) {
   prime.push_back (i);
   for (int j = i; j < maxn; j += i) {
    if (j != i) is[j] = false;
   }
  }
 }
}

void solve() {
  int n;
  cin >> n;
  int x = -1;
  for (int i: prime) {
   if ((i - 1) % (n - 1) == 0 && is[(i - 1) / (n - 1)] == false) x = (i - 1) / (n - 1);
  }
  assert (x != -1);
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < n; j++) {
    if (i == j) cout << 1 << ' ';
    else cout << x << ' ';
   }
   cout << '\n';
  }
}

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 seive();
 int t;
 cin >> t;
 while (t--) solve();
 return 0;
}
