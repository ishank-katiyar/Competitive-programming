#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 string s;
 cin >> s;
 if (s.back() == 's') s += "es";
 else s += "s";
 cout << s << '\n';
 return 0;
}
