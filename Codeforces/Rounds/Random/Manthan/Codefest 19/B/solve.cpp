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
 vector<int> a(n);
 for (auto& i: a) cin >> i;
 int ans = 1;
 vector<int> A(a);
 for (auto& i: a) A.push_back(i);
 debug(A);
 map <int, int> mp;
 map <int, int> index;
 int j = 0;
 mp[A[0]]++;
 index[A[0]] = 0;
 for (int i = 1; i < n; i++) {
  mp[A[i]]++;
  while (mp[A[i]] == 2) {
   j = max(index[A[i]] + 1, j);
   mp[A[i]]--;
  }
  index[A[i]] = i;
  if (j == 0) ans = max(ans, i + 1);
  if (i == n - 1) ans = max(ans, i - j + 1);
 }
 for (int i = n; i < 2 * n; i++) {
  mp[A[i]]++;
  while (mp[A[i]] == 2) {
   j = max(index[A[i]] + 1, j);
   mp[A[i]]--;
  }
  index[A[i]] = i;
  if (j < n) ans = max(ans, i - j + 1);
  else break;
 }
 cout << n - ans << '\n';
 return 0;
}
