#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
 return '"' + s + '"';
}

string to_string(const char* ch) {
 return to_string((string)ch);
}

string to_string(char ch) {
 return (string)"'" + ch + (string)"'";
}

string to_string(bool b) {
 return (b ? "true" : "false");
}

template<class A, class B>
string to_string(pair<A, B> p) {
 return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<class A>
string to_string(A a) {
 string res = "{";
 bool first = true;
 for(const auto& x: a) {
  if(first == false) res += ", ";
  first = false;
  res += to_string(x);
 }
 res += "}";
 return res;
}

void debug() {cerr << "]\n";}

template<class H, class... T>
void debug(H head, T... tail) {
 cerr << to_string(head) << " ";
 debug(tail...);
}

#ifdef LOCAL
 #define debug(...) cerr << "[" << #__VA_ARGS__ << " ] = ["; debug(__VA_ARGS__);
#else 
 #define debug(...) 
#endif
  
const int maxn = 111;
vector<string> a (maxn);
vector<vector<int>> ans;

void F (char &c) {
 if (c == '0') c = '1';
 else c = '0';
}

pair<int, int> ff(int x, int y, int code) {
 if (code == 0) {
  x--, y--;
  F(a[x][y]);
  return make_pair(x, y);
 }
 if (code == 1) {
  x--;
  F(a[x][y]);
  return make_pair(x, y);
 }
 if (code == 2) {
  x--, y++;
  F(a[x][y]);
  return make_pair(x, y);
 }
 if (code == 3) {
  y++;
  F(a[x][y]);
  return make_pair(x, y);
 }
 if (code == 4) {
  x++, y++;
  F(a[x][y]);
  return make_pair(x, y);
 }
 if (code == 5) {
  x++;
  F(a[x][y]);
  return make_pair(x, y);
 }
 if (code == 6) {
  x++, y--;
  F(a[x][y]);
  return make_pair(x, y);
 }
 y--;
 F(a[x][y]);
 return make_pair(x, y);
}

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  cin >> n >> m;
  int N = n;
  int M = m;
  ans.clear();
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }

  int CNT = 0;

  auto f = [&] (int x, int y, vector<int> code) {
   CNT++;
   // x++, y++;
   vector<int> ret;
   for (auto& i: code) {
    pair<int, int> p = ff(x, y, i);
    ret.push_back (p.first + 1);
    ret.push_back (p.second + 1);
   }
   assert ((int) ret.size() == 6);
   ans.push_back (ret);
   // return ret;
  };

  if (n % 2 == 1 && m % 2 == 1 && a[n - 1][m - 1] == '1') {
   f (n - 2, m - 1, {5, 6, 7});
  }

  if (n % 2 == 1) {
   // if (a[n - 1][0] == '1') {
   //  f (n - 1, 0, {1, 2, 3});
   // }
   for (int j = 0; j < m; j += 2) {
    int x = j;
    int y = j + 1;
    if (y >= m) continue;
    if (a[n - 1][x] == '1' && a[n - 1][y] == '1') {
     f (n - 1, x, {1, 2, 3});
     f (n - 1, y, {7, 0, 1});
    }
    else if (a[n - 1][x] == '0' && a[n - 1][y] == '0') {
     // nothing
    }
    else if (a[n - 1][x] == '0') {
     f (n - 1, x, {1, 2, 3});
    }
    else if (a[n - 1][y] == '0') {
     f (n - 1, y, {7, 0, 1});
    }
    else {
     assert (false);
    }
   }
   // n--;
  }
  if (m % 2 == 1) {
   // if (a[0][m - 1] == '1') {
   //  f (0, m - 1, {5, 6, 7});
   // }
   for (int i = 0; i < n; i += 2) {
    int x = i;
    int y = i + 1;
    if (y >= n) continue;
    if (a[x][m - 1] == '1' && a[y][m - 1] == '1') {
     f (x, m - 1, {5, 6, 7});
     f (y, m - 1, {7, 0, 1});
    }
    else if (a[x][m - 1] == '0' && a[y][m - 1] == '0') {
     // nothing
    }
    else if (a[x][m - 1] == '0') {
     f (x, m - 1, {5, 6, 7});
    }
    else if (a[y][m - 1] == '0') {
     f (y, m - 1, {7, 0, 1});
    }
    else {
     assert (false);
    }
   }
   // m--;
  }

  auto get_block = [&] (int i, int j) -> vector<string> {
   vector<string> aaa;
   string s1 = string (1, a[i][j]);
   string s2 = string (1, a[i][j + 1]);
   string s3 = string (1, a[i + 1][j]);
   string s4 = string (1, a[i + 1][j + 1]);
   aaa.push_back (s1 + s2);
   aaa.push_back (s3 + s4);
   return aaa;
  };

  function<void(int, int, vector<string>)> F = [&] (int i, int j, vector<string> aa) {
   vector<int> aaa = {0, 0, 1, 1};
   vector<int> bbb = {0, 1, 0, 1};
   vector<pair<int, int>> A;
   vector<pair<int, int>> B;
   for (int I = 0; I < 4; I++) {
    int x = aaa[I];
    int y = bbb[I];
    if (aa[x][y] == '1') {
     A.emplace_back (x + i, y + j);
    }
    else {
     B.emplace_back (x + i, y + j);
    }
   }
   int cnt = (int) A.size();
   if (cnt == 0) {
    return;
   }
   else if (cnt == 1) {
    if (aa[0][0] == '1') {
     f (i, j + 1, {5, 6, 7});
     F (i, j, get_block(i, j));
    }
    else {
     f (i, j, {3, 4, 5});
     F (i, j, get_block(i, j));
    }
   }
   else if (cnt == 2) {
    if (aa[0][0] == '1') {
     f (i, j, {3, 4, 5});
     F (i, j, get_block(i, j));
    }
    else if (aa[0][1] == '1') {
     f (i, j + 1, {5, 6, 7});
     F (i, j, get_block(i, j));
    }
    else if (aa[1][0] == '1') {
     f (i + 1, j, {1, 2, 3});
     F (i, j, get_block(i, j));
    }
    else if (aa[1][1] == '1') {
     f (i + 1, j + 1, {7, 0, 1});
     F (i, j, get_block(i, j));
    }
   }
   else if (cnt == 3) {
    if (aa[0][0] == '0') {
     f (i, j, {3, 4, 5});
     F (i, j, get_block(i, j));
    }
    else if (aa[0][1] == '0') {
     f (i, j + 1, {5, 6, 7});
     F (i, j, get_block(i, j));
    }
    else if (aa[1][0] == '0') {
     f (i + 1, j, {1, 2, 3});
     F (i, j, get_block(i, j));
    }
    else if (aa[1][1] == '0') {
     f (i + 1, j + 1, {7, 0, 1});
     F (i, j, get_block(i, j));
    }
   }
   else if (cnt == 4) {
    f (i, j, {3, 4, 5});
    F (i, j, get_block(i, j));
   }
   else {
    assert (false);
   }
  };

  vector<string> AA (n);
  for (int i = 0; i < n; i++) {
   string S = "";
   for (int j = 0; j < m; j++) {
    S += string (1, a[i][j]);
   }
   AA[i] = S;
  }
  debug ("after_odd", AA);

  for (int i = 0; i < (n - n % 2); i += 2) {
   for (int j = 0; j < (m - m % 2); j += 2) {
    vector<string> aaa = get_block(i, j);
    // debug (aaa);
    F (i, j, aaa);
    aaa = get_block(i, j);
    debug (aaa);
   }
  }
  assert (CNT <= N * M);
  for (int i = 0; i < n; i++) {
   string S = "";
   for (int j = 0; j < m; j++) {
    S += string (1, a[i][j]);
   }
   AA[i] = S;
  }
  debug (AA);
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
    assert (a[i][j] == '0');
   }
  }
  assert ((int) ans.size() == CNT);
  cout << CNT << '\n';
  for (auto& i: ans) {
   for (auto& j: i) cout << j << ' ';
   cout << '\n';
  }
 }
 return 0;
}
