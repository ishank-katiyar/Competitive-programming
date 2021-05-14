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
  int n = (int) s.size();
  deque<char> a;
  for (int i = 0; i < n; i++) {
   if (a.empty() == true) {
    a.push_back(s[i]);
   }  
   else {
    if (a.back() == 'A' && s[i] == 'B') {
     a.pop_back();
    }
    else a.push_back(s[i]);
   }
  }
  debug(a);
  int ans = 0;
  int cur1 = 0;
  int cur2 = 0;
  n = (int) a.size();
  for (int i = 0; i < n; i++) {
   if (a[i] == 'B') {
    cur2++;
    ans += cur1;
    cur1 = 0;
   } 
   else {
    ans += cur2 % 2;
    cur2 = 0;
    cur1++;
   }
  }
  if (cur1 > 0) {
   ans += cur1;
  }
  if (cur2 > 0) {
   ans += cur2 % 2;
  }
  cout << ans << '\n';
 }
 return 0;
}
