#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 string s;
 cin >> s;
 int ans = 0;
 for(auto& ch: s) ans += (ch - '0');
 cout << (ans % 9 ? "No\n" : "Yes\n");
}
