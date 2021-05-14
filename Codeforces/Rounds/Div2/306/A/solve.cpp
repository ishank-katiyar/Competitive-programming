#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 string s;
 cin >> s;
 int n = (int) s.size();
 bool ok1 = false, ok2 = false;
 for(int i = 0; i < n-1; i++) {
  if(ok1 == false && s[i] == 'A' && s[i+1] == 'B') {
   ok1 = true, i++;
   continue;
  }
  if(s[i] == 'B' && s[i+1] == 'A' && ok1) {
   ok2 = true, i++;
   continue;
  }
 }
 bool ans1 = ok1 && ok2;
 ok1 = ok2 = false;
 for(int i = 0; i < n-1; i++) {
  if(ok2 == false && s[i] == 'B' && s[i+1] == 'A') {
   ok2 = true, i++;
   continue;
  }
  if(s[i] == 'A' && s[i+1] == 'B' && ok2) {
   ok1 = true, i++;
   continue;
  }
 }
 bool ans2 = ok1 && ok2;
 //cout << ok1 << ok2 << '\n';
 cout << (ans1 || ans2 ? "YES\n" : "NO\n");
 return 0;
}
