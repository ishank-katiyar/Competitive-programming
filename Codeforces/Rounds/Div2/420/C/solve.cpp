#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 deque<int> d;
 int ans = 0;
 deque<bool> sorted;
 int N = 0;
 for (int i = 0; i < 2 * n; i++) {
  string S;
  cin >> S;
  if (S == "add") {
   int x;
   cin >> x;
   d.push_back(x);
   sorted.push_back(false);
  }
  else {
   N++;
   if (sorted.back() == true) {
   }
   else if (d.back() == N) {
    d.pop_back();
    sorted.pop_back();
   }
   else {
    ans++;
    sorted.push_back(true);
   }
  }
 }
 cout << ans << '\n';
 return 0;
}
