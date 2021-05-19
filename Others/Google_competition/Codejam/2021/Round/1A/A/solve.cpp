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
 int T;
 cin >> T;
 for (int tt = 1; tt <= T; tt++) {
  int n;
  cin >> n;
  vector<string> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
   int sz1 = int (a[i].size());
   int sz11 = int (a[i].size());
   int sz2 = int (a[i - 1].size());
   if (sz1 > sz2) {
    continue;
   }
   if (sz1 == sz2) {
    if (stoll (a[i]) <= stoll (a[i - 1])) {
     a[i] += "0";
     ans += 1;
    }
    continue;
   }
   // while ((int)a[i].size() < ((int) a[i - 1].size()) - 1) {
   //  ans += 1;
   //  a[i] += "9";
   // }
   // sz1 = int (a[i].size());
   // sz2 = int (a[i - 1].size());
   // assert (sz1 == sz2 - 1);
   // for (int j = 0; j < 10; j += 1) {
   //  if (stoll (a[i] + string (1, '0' + j)) > stoll (a[i - 1])) {
   //   a[i] += string (1, '0' + j);
   //   ans += 1;
   //   break;
   //  }
   // }
   // if ((int) a[i].size() < (int) a[i - 1].size()) {
   //  a[i] += "00";
   //  ans += 2;
   // }
   
   assert (sz1 < sz2);

   // auto check = [] (string A, string B, int N) -> bool {
   //  bool ok = true;
   //  for (int I = 0; I < N; I++) {
   //   ok &= (A[I] >= B[I]);
   //  }
   //  return ok;
   // };

   auto check1 = [] (string A, int I, int J) -> bool {
    bool ok = true;
    for (int k = I; k <= J; k++) {
     ok &= (A[k] == '9');
    }
    return ok;
   };

   if (stoll (a[i]) > stoll (a[i - 1].substr (0, sz1))) {
    int xx = sz2 - sz1;
    ans += xx;
    a[i] += string (xx, '0');
    continue;
   }

   if (stoll (a[i]) < stoll (a[i - 1].substr (0, sz1)) || check1 (a[i - 1], sz1, sz2 - 1) == true) {
    int xx = sz2 - sz1 + 1;
    ans += xx;
    a[i] += string (xx, '0');
    continue;
   }

   if (stoll (a[i]) == stoll (a[i - 1].substr (0, sz1)) && check1 (a[i - 1], sz1, sz2 - 1) == true) {
    int xx = sz2 - sz1 + 1;
    ans += xx;
    a[i] += string (xx, '0');
    continue;
   }

   for (int j = sz1; j < sz2; j++) {
    a[i] += a[i - 1][j];
    ans += 1;
   }
   sz1 = (int) a[i].size();
   sz2 = (int) a[i - 1].size();
   assert (sz1 == sz2);
   int j = sz2 - 1;
   while (j >= 0) {
    if (a[i][j] != '9') {
     a[i][j] += 1;
     break;
    }
    j -= 1;
   }
   assert (j >= sz11);
   for (int k = j + 1; k < sz2; k++) {
    a[i][k] = '0';
   }
  }
  debug (a);
  cout << "Case #" << tt << ": " << ans << '\n';
 }
 return 0;
}
