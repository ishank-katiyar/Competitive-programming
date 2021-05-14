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
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<long long int> a(n);
  long long int sum = 0;
  for (auto& i: a) cin >> i, sum += i;
  if (sum % n) {
   cout << -1 << '\n';
   continue;
  }
  long long int x = sum / n;
  vector<pair<pair<int, int>, long long int>> ans;
  auto g = [&] (int i, int j, int X) {
   i++;
   j++;
   ans.push_back(make_pair(make_pair(i, j), X));
   assert (a[i - 1] >= X * i);
   a[i - 1] -= X * i;
   a[j - 1] += X * i;
  };
  for (int i = 1; i < n; i++) {
   g(0, i, (i + 1 - (a[i] % (i + 1))) % (i + 1));
   g(i, 0, a[i] / (i + 1));
  }
  for (int i = 1; i < n; i++) {
   g(0, i, x);
  }
  for (int i = 0; i < n; i++) {
   assert (a[i] == x);
  }
  cout << (int) ans.size() << '\n';
  for (auto& i: ans) cout << i.first.first << ' ' << i.first.second << ' ' << i.second << '\n';
 }
 return 0;
}
