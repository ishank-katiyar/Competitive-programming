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
  string s;
  cin >> s;
  bool ok = false;
  for (int i = 0; i < 2; i++) {
   for (int j = 0; j < 2; j++) {
    for (int k = 0; k < 2; k++) {
     string S = s;
     for (auto& I: S) {
      if (I == 'A') {
       if (i == 0) I = '(';
       else I = ')';
      }
      if (I == 'B') {
       if (j == 0) I = '(';
       else I = ')';
      }
      if (I == 'C') {
       if (k == 0) I = '(';
       else I = ')';
      }
     }
     vector<char> ss;
     for (auto& I: S) {
      if (ss.empty() == true) {
       ss.push_back (I);
      } else {
       if (ss.back() == '(' && I == ')') {
        ss.pop_back();
       } else {
        ss.push_back (I);
       }
      }
     }
     debug (s, S);
     ok |= (ss.empty());
    }
   }
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
