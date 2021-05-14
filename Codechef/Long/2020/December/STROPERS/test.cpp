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
 string s;
 cin >> s;
 int n = (int) s.size();
 int cnt1 = count (s.begin(), s.end(), '1');
 map <string, int> mp;

 function<void(string)> f = [&] (string S) {
  // debug ("called", S);
  if (mp.count (S)) return;
  mp[S] = 1;
  int cnt_pre = 0;
  for (int i = 0; i < n; i++) {
   if (S[i] == '0') break;
   cnt_pre++;
  } 
  if (cnt_pre >= cnt1 - 1) {
   debug ("actual ans", S);
   // cout << S << '\n';
  }
  for (int i = 0; i < n; i++) {
   for (int len = 1; len <= n; len++) {
    if (n - i < len) continue;
    int cnt_1 = 0;
    for (int j = i; j <= i + len - 1; j++) {
     if (S[j] == '1') cnt_1++;
    }
    if (cnt_1 % 2 == 1) continue;
    assert (i + len - 1 < n);
    if (S[i] == '0' && S[i + len - 1] == '1') {
     string temp = S;
     string temp_sub = S.substr (i, len);
     reverse (temp_sub.begin(), temp_sub.end());
     for (int j = i; j <= i + len - 1; j++) {
      temp[j] = temp_sub[j - i];
     }
     if (mp.count (temp) == 0)  {
      // debug ("looking at", S.substr (i, len), "in", S, "and call", i, len, cnt_1);
      f (temp);
     }
    }
   }
  }
 };
 
 f (s);
 return 0;
}
