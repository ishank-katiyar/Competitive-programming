#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 string s;
 cin >> s;
 cout << ((s[0] == s[1]) && (s[1] == s[2]) ? "Won": "Lost") << '\n';
 return 0;
}
