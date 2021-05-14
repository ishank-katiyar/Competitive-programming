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
 for (int tt = 1; tt <= t; tt++)  {
  int x, y;
  cin >> x >> y;

  string s;
  cin >> s;

  int ans = 0;
  
  auto f = [&] (char a, char b) {
   assert (a != '?');
   assert (b != '?');
   if (a == b) {
    return;
   }
   if (a == 'C') {
    ans += x;
   } else {
    ans += y;
   }
  };

  int n = static_cast <int> (s.size());

  if (count (s.begin(), s.end(), '?') == n) {
   cout << "Case #" << tt << ": " << 0 << '\n';
   continue;
  }

  while (s.front() == '?') {
   s.erase (s.begin());
  }

  while (s.back() == '?') {
   s.erase (--s.end());
  }

  debug (s);

  n = static_cast <int> (s.size());

  for (int i = 1; i < n; i++) {
   if (s[i] == '?') {
    char prev = s[i - 1];
    int j = i;
    while (s[j] == '?') {
     j += 1;
    }
    assert (j < n);
    char next = s[j];
    if (prev != next) {
     f (prev, next);
    }
    i = j;
   } else {
    f (s[i - 1], s[i]);
   }
  }
  cout << "Case #" << tt << ": " << ans << '\n';
 }
 return 0;
}
