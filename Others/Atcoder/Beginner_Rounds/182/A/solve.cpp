#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int a, b;
 cin >> a >> b;
 cout << max (2 * a + 100 - b, 0) << '\n';
 return 0;
}
