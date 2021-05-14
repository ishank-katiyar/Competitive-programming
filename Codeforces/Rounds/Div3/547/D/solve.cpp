#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 string a, b;
 cin >> a >> b;
 map<char, vector<int>> A, B;
 for (int i = 0; i < n; i++) A[a[i]].push_back(i + 1);
 for (int i = 0; i < n; i++) B[b[i]].push_back(i + 1);
 vector<pair<int, int>> ans;
 for (int i = 0; i < 26; i++) {
  while (A[i + 'a'].empty() == false && B[i + 'a'].empty() == false) ans.emplace_back(A[i + 'a'].back(), B[i + 'a'].back()), A[i + 'a'].pop_back(), B[i + 'a'].pop_back();
 }
 char ch = '?';
 for (int i = 0; i < 26; i++) {
  while (A[i + 'a'].empty() == false && B[ch].empty() == false) ans.emplace_back(A[i + 'a'].back(), B[ch].back()), A[i + 'a'].pop_back(), B[ch].pop_back();
 }
 for (int i = 0; i < 26; i++) {
  while (A[ch].empty() == false && B[i + 'a'].empty() == false) ans.emplace_back(A[ch].back(), B[i + 'a'].back()), A[ch].pop_back(), B[i + 'a'].pop_back();
 }
 while (A[ch].empty() == false && B[ch].empty() == false) ans.emplace_back(A[ch].back(), B[ch].back()), A[ch].pop_back(), B[ch].pop_back();
 cout << (int) ans.size() << '\n';
 for (auto& i: ans) cout << i.first << ' ' << i.second << '\n'; 
 return 0;
}
