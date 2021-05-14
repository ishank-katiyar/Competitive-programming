#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e6 + 1;
vector<bool> is (maxn, true);
vector<int> p;

void seive() {
 is[0] = is[1] = false;
 for (int i = 2; i < maxn; i++) {
  if (is[i]) {
   p.push_back (i);
   for (int j = 2 * i; j < maxn; j += i) {
    is[j] = false;
   }
  }
 }
}

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 seive();
 // cout << (int) p.size() << '\n';
 reverse (p.begin(), p.end());
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> b (n);
  for (int i = 0; i < n; i++) {
   cin >> b[i];
  }
  map <int, int> mp;
  vector<int> a (n);
  for (int i = 0; i < n; i++) {
   if (b[i] != i - 1) {
    if (mp.count(b[i] - 1)) {
     a[i] = mp[b[i] - 1];
    }
    else {
     mp[b[i] - 1] = p.back();
     a[i] = p.back();
     p.pop_back();
    }
   }
   else {
    if (mp.count(i)) {
     a[i] = mp[i];   
     mp.erase (i);
    }
    else {
     a[i] = p.back();
     p.pop_back();
    }
   }
  }
  for (int i = 0; i < n; i++) {
   cout << a[i] << ' ';
  }
  cout << '\n';
 }
 return 0;
}
