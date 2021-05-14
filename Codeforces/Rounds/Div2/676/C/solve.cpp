#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 string s;
 cin >> s;
 int n = (int) s.size();
 vector<pair<char, int>> ans;
 ans.emplace_back('R', 2);
 for (int i = n - 2; i >= 1; i--) s += s[i];
 //cerr << s << endl;
 n = (int) s.size();
 ans.emplace_back('R', n - 1);
 n = (int) s.size();
 s += s[n - 2];
 //cerr << s << endl;
 n = (int) s.size();
 ans.emplace_back('L', n - 1);
 string ss = s.substr(1, n - 2);
 s = ss + s;
 //cerr << s << endl;
 ans.emplace_back('L', 2);
 s = s[1] + s;
 //cerr << s << endl;
 string rev = s;
 reverse(rev.begin(), rev.end());
 assert (rev == s);
 cout << (int) ans.size() << '\n';
 for (auto& i: ans) cout << i.first << ' ' << i.second << '\n';
 return 0;
}
