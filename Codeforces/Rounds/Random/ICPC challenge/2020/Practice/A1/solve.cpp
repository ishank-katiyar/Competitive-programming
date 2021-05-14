#include <bits/stdc++.h>

using namespace std;

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 int n;
 cin >> n;
 vector<__int64> a(n);
 for(__int64& i : a) cin >> i;
 sort(a.begin() , a.end());
 for(auto& i : a) cout << i << ' '; 
 cout << '\n';
 return 0;
}
