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

const int maxn = 2e5 + 1;
vector<vector<int>> sf (maxn, vector<int> ());
vector<bool> is (maxn, true);

void seive() {
 is[0] = is[1] = false;
 for (int i = 2; i < maxn; i++) {
  if (is[i] == true) {
   for (int j = i; j < maxn; j += i) {
    sf[j].push_back (i);
    if (j != i) is[j] = false;
   }
  }
 }
}

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 seive();
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> a (n);
  for (auto& i: a) cin >> i;
  map <int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
   for (auto& j: sf[a[i]]) {
    mp[j].push_back (i);
   }
  }
  debug (mp);
  vector<int> c (n, 0);
  for (auto& i: mp) {
   int first = i.second[0];
   int last = i.second.back();
   assert (first >= 0 && first < n);
   assert (last >= 0 && last < n);
   c[first]--;
   c[last]++;
  }
  debug (c);
  int ans = -1;
  int sum = 0;
  for (int i = 0; i < n; i++) {
   sum += c[i];
   if (sum == 0) {
    ans = i + 1;
    break;
   }
  }
  assert (ans != -1);
  cout << ans << '\n';
 }
 return 0;
}
