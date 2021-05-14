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
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 deque<int> a(n);
 for (auto& i: a) cin >> i;
 sort (a.begin(), a.end());
 debug(a);
 cout << (n - 1) / 2 << '\n';
 while (n > 1) {
  cout << a.back() << ' ';
  a.pop_back();
  if (a.empty() == false) cout << a.front() << ' ';
  a.pop_front();
  debug(a);
  n -= 2;
 }
 if (n) cout << a.back() << ' ';
 cout << '\n';
 return 0;
}
