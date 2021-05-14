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
 vector<pair<int, int>> a(n);
 map<pair<int, int>, vector<int>> mp;
 int c = 1;
 for (auto& i: a) cin >> i.first >> i.second, mp[i].push_back(c++);
 sort (a.begin(), a.end(), [&] (const pair<int, int> A, const pair<int, int> b) -> bool {
  if (A.first == b.first) return A.second > b.second; 
  return A.first < b.first;
 });
 debug(a);
 multiset<pair<int, int>> s;
 s.insert(make_pair(a[0].second, a[0].first));
 for (int i = 1; i < n; i++) {
  auto it = s.lower_bound(make_pair(a[i].second, INT_MIN));
  if (it == s.end()) {
   s.insert (make_pair(a[i].second, a[i].first)); 
   continue;
  }
  if (it->first >= a[i].second) {
   pair<int, int> p = a[i];
   pair<int, int> p1 = make_pair(it->second, it->first);
   if (p == p1) cout << mp[p][0] << ' ' << mp[p][1] << '\n';
   else cout << mp[p][0] << ' ' << mp[p1][0] << '\n';
   return 0;
  } 
  assert (false);
  s.insert (make_pair(a[i].second, a[i].first)); 
 }
 cout << "-1 -1\n";
 return 0;
}
