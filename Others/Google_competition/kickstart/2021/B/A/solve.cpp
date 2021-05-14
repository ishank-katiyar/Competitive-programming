#include <bits/stdc++.h>

using namespace std;

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int TT;
  cin >> TT;
  for (int ttt = 1; ttt <= TT; ttt++) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      int j = i - 1;
      while (j >= 0 && s[j] < s[j + 1]) {
        j -= 1;
      }
      ans.push_back (i - j);
    }
    cout << "Case #" << ttt << ": ";
    for (auto& i: ans) cout << i << ' ';
    cout << '\n';
  }
  return 0;
}
