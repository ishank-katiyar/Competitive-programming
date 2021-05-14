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

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  cin >> n >> m;
  vector<int> a (n), b (m);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
   cin >> b[i];
  }

  auto f = [] (vector<int> A, vector<int> B) -> int {
   int N = static_cast <int>  (A.size());
   int M = static_cast <int>  (B.size());
   if (N == 0 || M == 0) {
    return 0;
   }
   map <int, int> mp;
   for (auto& i: A) {
    mp[i]++;
   }
   vector<int> dp (M + 1);
   dp[M - 1] = mp.count (B[M - 1]) > 0;
   for (int i = M - 2; i >= 0; i--) {
    dp[i] += dp[i + 1] + (mp.count (B[i]) > 0);
   }
   int ans = 0;
   for (int i = 0; i < M; i++) {
    int x = upper_bound (A.begin(), A.end(), B[i]) - A.begin();
    if (i == 0 && x > 0) {
     ans = 1;
    } 
    int j = upper_bound (B.begin(), B.end(), B[i] - x) - B.begin();
    if (x == 0) {
     assert (j == i + 1);
     continue;
    }
    assert (j <= i + 1);
    ans = max (ans, i - j + 1 + dp[i + 1]);
   }
   return ans;
  };

  vector<int> Apos, Aneg, Bpos, Bneg;
  for (auto& i: a) {
   if (i > 0) Apos.push_back (i);
   else Aneg.push_back (-i);
  }
  for (auto& i: b) {
   if (i > 0) Bpos.push_back (i);
   else Bneg.push_back (-i);
  }
  sort (Apos.begin(), Apos.end());
  sort (Bpos.begin(), Bpos.end());
  sort (Aneg.begin(), Aneg.end());
  sort (Bneg.begin(), Bneg.end());
  debug ()
  cout << f (Apos, Bpos) + f (Aneg, Bneg) << '\n';
 }
 return 0;
}
