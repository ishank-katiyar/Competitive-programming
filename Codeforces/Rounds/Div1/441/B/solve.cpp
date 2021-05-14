#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 int N = n;
 vector<int> a(n);
 for (int i = 0; i < N; i++) {
  cin >> a[i];
 }
 cout << 1 << ' ';
 set<int> s;
 for (int i = 0; i < N; i++) {
  s.insert (a[i]);
  while (s.empty() == false && *(--s.end()) == n) s.erase(--s.end()), n--;
  cout << (int) s.size() + 1 << ' ';
 }
 return 0;
}
