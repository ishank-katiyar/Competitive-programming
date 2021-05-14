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
 int q;
 cin >> q;
 map<pair<long long int, long long int>, long long int> cost;

 auto get = [&] (long long int x, long long int y) -> long long int {
  map<long long int, int> mp;
  while (y > 0) {
   mp[y]++;
   y /= 2;
  }
  while (x > 0) {
   mp[x]++;
   x /= 2;
  }
  long long ans = 0;
  for (auto& i: mp) {
   if (i.second == 2) ans = max(ans, i.first);
  }
  return ans;
 };

 while (q--) {
  int type;
  cin >> type;
  if (type == 1) {
   long long int x, y, w;
   cin >> x >> y >> w;
   long long int lca = get(x, y);
   debug(lca, x, y);
   while (1) {
    if (lca == 1) break;
    long long int ancestor = lca / 2;
    cost[make_pair(ancestor, lca)] -= 2 * w;
    lca = ancestor;
   }
   while (1) {
    if (y == 1) break;
    long long int ancestor = y / 2;
    cost[make_pair(ancestor, y)] += w;
    y = ancestor;
   }
   while (1) {
    if (x == 1) break;
    long long int ancestor = x / 2;
    cost[make_pair(ancestor, x)] += w;
    x = ancestor;
   }
   debug(cost);
  }
  else {
   long long int x, y;
   cin >> x >> y;
   long long int ans = 0;
   long long int lca = get(x, y);
   while (1) {
    if (lca == 1) break;
    long long int ancestor = lca / 2;
    if (cost.count (make_pair(ancestor, lca))) ans -= 2 * cost[make_pair(ancestor, lca)];
    lca = ancestor;
   }
   while (1) {
    if (y == 1) break;
    long long int ancestor = y / 2;
    if (cost.count (make_pair(ancestor, y))) ans += cost[make_pair(ancestor, y)];
    y = ancestor;
   }
   while (1) {
    if (x == 1) break;
    long long int ancestor = x / 2;
    if (cost.count (make_pair(ancestor, x))) ans += cost[make_pair(ancestor, x)];
    x = ancestor;
   }
   cout << ans << '\n';
  }
 }
 return 0;
}
