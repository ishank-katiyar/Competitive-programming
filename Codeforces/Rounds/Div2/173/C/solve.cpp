#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 string a, b;
 cin >> a >> b;
 int c1 = count (a.begin(), a.end(), '1');
 int c2 = count (b.begin(), b.end(), '1');
 bool ok = ((int) a.size() == (int) b.size()) && ((c1 > 0 && c2 > 0) || (c1 == 0 && c2 == 0));
 cout << (ok ? "YES" : "NO") << '\n';
 return 0;
}
