#include <bits/stdc++.h>
using namespace std;

const int W = 1e5 + 1;
vector<bool> subset(W);

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<int> a(n);
 for(auto& i: a) cin >> i;
 subset[0] = true;
 for(int i = 0; i < n; i++) {
  for(int j = W - a[i]; j >= 0; j--) {
   if(subset[j] == true) subset[j + a[i]] = true;
  }
 }
 vector<int> ans;
 for(int i = 1; i < W; i++) if(subset[i] == true) ans.push_back(i);
 cout << (int) ans.size() << '\n';
 for(auto& i: ans) cout << i << ' ';
 cout << '\n';
 return 0;
}
