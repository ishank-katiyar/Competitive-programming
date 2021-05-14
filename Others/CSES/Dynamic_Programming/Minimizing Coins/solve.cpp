#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, x;
 cin >> n >> x;
 vector<int> a(n);
 for(auto& i: a) cin >> i;
 vector<int> sub(x+1, 1e9);
 sub[0] = 0;
 for(int i = 0; i < n; i++) {
  for(int j = 0; j <= x - a[i]; j++) {
   sub[j + a[i]] = min(sub[j + a[i]], sub[j] + 1); 
  }
 }
 cout << (sub[x] == 1e9 ? -1 : sub[x]) << '\n';
 return 0;
}
