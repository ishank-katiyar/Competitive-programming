#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  int n;
  cin >> n;
  set<int> s;
  for(int i = 0; i < n-1; i++) {
   int x;
   cin >> x;
   s.insert(x);
  }
  for(int i = 1; i <= n; i++) {
   if(s.count(i) == 0) {
    cout << i << '\n';
    break;
   }
  } 
 }
}
