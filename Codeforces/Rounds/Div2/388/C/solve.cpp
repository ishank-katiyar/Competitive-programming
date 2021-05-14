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

string to_string(vector<bool> v) {
 bool first = true;
 string res = "{";
 for (int i = 0; i < static_cast<int>(v.size()); i++) {
  if (!first) {
   res += ", ";
  }
  first = false;
  res += to_string(v[i]);
 }
 res += "}";
 return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
 string res = "";
 for (size_t i = 0; i < N; i++) {
  res += static_cast<char>('0' + v[i]);
 }
 return res;
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
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 string s;
 cin >> s;
 set<int> d, r;
 vector<bool> denied(n, true);
 for (int i = 0; i < n; i++) {
  if (s[i] == 'D') d.insert(i);
  else r.insert(i);
 }
 int i = 0;
 while (1) {
  if (i == n) i = 0;
  if (d.empty() == true) {
   cout << 'R' << '\n';
   break;
  }
  if (r.empty() == true) {
   cout << 'D' << '\n';
   break;
  }
  if (denied[i] == false) {
   i++;
   continue;
  }
  if (s[i] == 'D') {
   auto it = r.lower_bound(i);
   if (it == r.end()) it = r.begin();
   denied[*it] = false;
   r.erase(it);
  }
  if (s[i] == 'R') {
   auto it = d.lower_bound(i);
   if (it == d.end()) it = d.begin();
   denied[*it] = false;
   d.erase(it);
  }
  i++;
  debug(denied);
 }
 return 0;
}
