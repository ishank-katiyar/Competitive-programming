#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 map<int, int> mp;
 vector<int> a(n);
 for (auto& i: a) cin >> i, mp[i]++;
 map<int, vector<int>> M;
 for (auto& i: mp) M[i.second].push_back(i.first);
 vector<int> A, B;
 bool ok = true;
 if (M.count(1)) {
  for (auto& i: M[1]) {
   if (ok) A.push_back(i);
   else B.push_back(i);
   ok = !ok;
  }
  if ((int) M[1].size() % 2 == 1) ok = false;
 }
 if (ok == false && M.size() == 1) {
  cout << "NO" << '\n';
  return 0;
 }
 M.erase(1);
 if (ok == false && M.size() == 1 && M.count(2)) {
  cout << "NO" << '\n';
  return 0;
 }
 for (auto& i: M) {
  int X = i.first;
  for (auto& j: i.second) {
   for (int k = 0; k < X; k++) {
    A.push_back(j);
   }
  }
 } 
 if (ok == false) {
  B.push_back(A.back());
  A.pop_back();
 }
 string ans = "";
 for (auto& i: a) {
  if (count(A.begin(), A.end(), i) > 0) {
   ans += 'A';
   A.erase(find(A.begin(), A.end(), i));
  }
  else {
   ans += 'B';
   B.erase(find(B.begin(), B.end(), i));
  }
 }
 cout << "YES" << '\n';
 cout << ans << '\n';
 return 0;
}
