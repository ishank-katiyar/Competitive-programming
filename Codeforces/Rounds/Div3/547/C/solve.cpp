#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<ll> a(n - 1);
 ll pre = 0;
 ll ans = 0;
 for (auto& i: a) cin >> i, pre += i, ans = min(ans, pre);
 vector<ll> A(n);
 A[0] = (ans * -1) + 1;
 for (int i = 1; i < n; i++) A[i] = A[i - 1] + a[i - 1];
 set<ll> s(A.begin(), A.end());
 bool ok = ((int) s.size() == n && *(--s.end()) == n);
 if (ok) for (auto& i: A) cout << i << ' ';
 else cout << -1;
 cout << '\n';
 return 0;
}
