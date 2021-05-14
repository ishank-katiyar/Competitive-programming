#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int r, o, c;
 cin >> r >> o >> c;
 cout << (c + ((20 - o) * 36) > r ? "YES" : "NO") << '\n';
 return 0;
}
