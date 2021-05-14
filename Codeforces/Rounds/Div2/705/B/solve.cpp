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
  int H, M;
  cin >> H >> M;
  string s;
  cin >> s;
  pair<int, int> p = make_pair(stoi(s.substr(0,2)), stoi(s.substr(3)));
  debug (p);
  pair<int, int> pp = p;

  map<int, int> mp;
  mp[0] = 0;
  mp[1] = 1;
  mp[2] = 5;
  mp[5] = 2;
  mp[8] = 8;

  auto mirror = [&] (pair<int, int> P) -> bool {
   debug("mirror", P);
   int x = P.first;   
   if (mp.count(x % 10) == 0) {
    return false;
   }
   if (mp.count (x / 10) == 0) {
    return false;
   }
   x = P.second;   
   if (mp.count(x % 10) == 0) {
    return false;
   }
   if (mp.count (x / 10) == 0) {
    return false;
   }
   return true;
  };

  auto mirror_ret = [&] (pair<int, int> P) -> pair<string, string> {
   debug("mirror_ret", P);
   // return make_pair((P.second % 10) * 10 + (P.second / 10), (P.first % 10) * 10 + (P.first / 10));
   string s1 = to_string(P.first);
   if (static_cast <int> (s1.size()) == 1) {
    s1 = "0" + s1;
   }
   string s2 = to_string(P.second);
   if (static_cast <int> (s2.size()) == 1) {
    s2 = "0" + s2;
   }
   assert (static_cast<int> (s1.size()) == 2);
   assert (static_cast<int> (s2.size()) == 2);
   return make_pair(s1, s2);
  };

  auto f = [&] (pair<int, int> P) -> pair<int, int> {
   debug("f", P);
   return make_pair(mp[P.second % 10] * 10 + mp[P.second / 10], mp[P.first % 10] * 10 + mp[P.first / 10]);
  };

  auto is_valid = [&] (pair<int, int> P) -> bool {
   debug("is_valid", P);
   P = f(P);
   debug("mirrored", P);
   if (P.first >= H || P.second >= M) {
    return false;
   }
   return true;
  };

  do {
   if (mirror(p)) {
    if (is_valid(p)) {
     break;
    }
   }
   p.second += 1;
   if (p.second == M) {
    p.second = 0;
    p.first += 1;
   }
   if (p.first == H) {
    p.first = 0;
   }
  } while (pp != p);
  cout << mirror_ret(p).first << ":" << mirror_ret(p).second << '\n';
 }
 return 0;
}
