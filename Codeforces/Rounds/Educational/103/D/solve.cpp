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
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> suf (n + 1, -1);
  for (int i = 0; i < n; i++) {
   if (suf[i] == -1) {
    if (s[i] == 'L')  suf[i] = 1;
    else {
     int j = i + 1;
     while (j < n && s[j] != s[j - 1]) j++;
     for (int k = j - 1; k >= i; k--) {
      suf[k] = j - k + 1;
     }
    }
   } else {
    if (s[i] == 'L') {
     suf[i] = 1;
    }
   }
  }
  suf[n] = 1;
  debug (suf);
  vector<int> pre (n + 1, -1);
  for (int i = n; i >= 1; i--) {
   if (pre[i] == -1) {
    if (s[i - 1] == 'R') {
     pre[i] = 1;
    } else {
     int j = i - 2;
     while (j >= 0 && s[j] != s[j + 1]) {
      j--;
     }
     for (int k = j + 2; k <= i; k++) {
      pre[k] = k - j;
     }
    }
   } else {
    if (s[i - 1] == 'R') {
     pre[i] = 1;
    }
   }
  }
  pre[0] = 1;
  debug (pre);
  for (int i = 0; i <= n; i++) {
   cout << pre[i] + suf[i] - 1 << ' ';
  }
  cout << '\n';
 }
 return 0;
}
