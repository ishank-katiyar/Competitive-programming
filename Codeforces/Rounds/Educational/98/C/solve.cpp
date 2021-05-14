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
  string S;
  cin >> S;

  // {{{
  // int ss1 = 0, ss2 = 0;
  // 
  // auto f0 = [&] (string s) -> bool {
  //  string s1 = "";
  //  string s2 = "";
  //  for (auto& i: s) {
  //   if (i == ')' || i == '(') s1 += i;
  //   else s2 += i;
  //  }
  //  int sz1 = (int) s1.size();
  //  int sz2 = (int) s2.size();
  //  debug (sz1, sz2);
  //  vector<char> S1;
  //  vector<char> S2;
  //  for (int i = 0; i < sz1; i++) {
  //   if (S1.empty() == true) {
  //    S1.push_back (s1[i]);
  //   }
  //   else {
  //    if (S1.back() == '(' && s1[i] == ')') {
  //     S1.pop_back();
  //     // return false;
  //    }
  //    else {
  //     S1.push_back (s1[i]);
  //    }
  //   }
  //  }
  //  ss1 = (int) S1.size();
  //  for (int i = 0; i < sz2; i++) {
  //   if (S2.empty() == true) {
  //    S2.push_back (s2[i]);
  //   }
  //   else {
  //    if (S2.back() == '[' && s2[i] == ']') {
  //     S2.pop_back();
  //     // return false;
  //    }
  //    else {
  //     S2.push_back (s2[i]);
  //    }
  //   }
  //  }
  //  ss2 = (int) S2.size();
  //  debug (ss1, ss2);
  //  if (ss1 == sz1 && ss2 == sz2) return true;
  //  return false;
  // };
  // 
  // auto f1 = [&] (string s) -> bool {
  //  vector<char> SS;
  //  int n = (int) s.size();
  //  for (int i = 0; i < n; i++) {
  //   if (SS.empty() == true) {
  //    SS.push_back (s[i]);
  //   }
  //   else {
  //    if (SS.back() == '(' && s[i] == ')') {
  //     SS.pop_back();
  //    }
  //    else if (SS.back() == '[' && s[i] == ']') {
  //     SS.pop_back();
  //    }
  //    else {
  //     SS.push_back (s[i]);
  //    }
  //   }
  //  }
  //  if ((int) SS.size() == ss1 + ss2) {
  //   return true;
  //  }
  //  return false;
  // };
  // 
  // int ans = 2;
  // if (f0 (S) == true) ans = 0;
  // if (f1 (S) == true) ans = 1;
  // cout << ans << '\n';
  // }}}

  string s1 = "";
  string s2 = "";
  for (auto& i: S) {
   if (i == ')' || i == '(') s1 += i;
   else s2 += i;
  }
  int sz1 = (int) s1.size();
  int sz2 = (int) s2.size();
  int ans = 0;
  vector<char> S1;
  vector<char> S2;
  for (int i = 0; i < sz1; i++) {
   if (S1.empty() == true) {
    S1.push_back (s1[i]);
   }
   else {
    if (S1.back() == '(' && s1[i] == ')') {
     S1.pop_back();
     ans++;
     // return false;
    }
    else {
     S1.push_back (s1[i]);
    }
   }
  }
  for (int i = 0; i < sz2; i++) {
   if (S2.empty() == true) {
    S2.push_back (s2[i]);
   }
   else {
    if (S2.back() == '[' && s2[i] == ']') {
     S2.pop_back();
     ans++;
     // return false;
    }
    else {
     S2.push_back (s2[i]);
    }
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
