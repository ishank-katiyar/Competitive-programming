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
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
   int x, y;
   cin >> x >> y;
   a.push_back (make_pair (x, y));
  }
  int ans = 0;
  while (n > 1) {
   pair<int, int> p = {-1, -1};
   int mx = 0;
   for (int i = 0; i < n; i++) {
    int cur_cnt = 0;
    for (int j = 0; j < n; j++) {
     int dist = abs (a[i].first - a[j].first) + abs (a[i].second - a[j].second);
     if (dist <= k) {
      cur_cnt++;
     }
    }
    if (cur_cnt > mx) {
     mx = cur_cnt;
     p = a[i];
    }
   }
   vector<pair<int, int>> new_a;
   new_a.push_back (p);
   for (int i = 0; i < n; i++) {
    int dist = abs (a[i].first - p.first) + abs (a[i].second - p.second);
    if (dist > k) {
     new_a.push_back (a[i]);
    }
   }
   if (n == (int) new_a.size()) {
    ans = -1;
    break;
   }
   n = (int) new_a.size();
   a = new_a;
   ans++;
  }
  cout << ans << '\n';
 }
 return 0;
}
