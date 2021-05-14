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
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  bool ok = true;
  for (int i = 0; a + b - 1 - i > i; i++) {
   if (s[i] == '?' && s[a + b - 1 - i] == '?') {
    continue;
   } 
   if (s[i] == '?' || s[a + b - 1 - i] == '?') {
    if (s[i] == '?') {
     s[i] = s[a + b - 1 - i];
    } else {
     s[a + b - 1 - i] = s[i];
    }
   } else {
    ok &= (s[i] == s[a + b - 1 - i]);
   } 
  }
  int cnt0 = count (s.begin(), s.end(), '0');
  int cnt1 = count (s.begin(), s.end(), '1');
  if (cnt0 > a || cnt1 > b || ok == false) {
   cout << -1 << '\n';
   continue;
  }
  for (int i = 0; a + b - 1 - i > i; i++) {
   if (s[i] == '?')  {
    assert (s[a + b - 1 - i] == '?');
    if (cnt0 + 2 <= a) {
     s[i] = s[a + b - 1 - i] = '0';
     cnt0 += 2;
    } else if (cnt1 + 2 <= b) {
     s[i] = s[a + b - 1 - i] = '1';
     cnt1 += 2;
    }
   } else {
    assert (s[a + b - 1 - i] != '?');
   }
  }
  int cnt = count (s.begin(), s.end(), '?');
  debug (s);
  if (cnt > 1) {
   cout << -1 << '\n';
   continue;
  }
  if (cnt == 1) {
   if (cnt0 < a) {
    replace (s.begin(), s.end(), '?', '0');
   } else if (cnt1 < b) {
    replace (s.begin(), s.end(), '?', '1');
   }
  }
  cnt0 = count (s.begin(), s.end(), '0');
  cnt1 = count (s.begin(), s.end(), '1');
  if (cnt0 == a && cnt1 == b) {
   cout << s << '\n';
  } else {
   cout << -1 << '\n';
  }
 }
 return 0;
}
