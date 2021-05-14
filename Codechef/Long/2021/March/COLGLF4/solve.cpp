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
  int64_t n, e, h;
  cin >> n >> e >> h;
  vector<pair<int64_t, int64_t>> a (3);
  for (int i = 0; i < 3; i++) {
   cin >> a[i].first;
   a[i].second = i + 1;
  }
  sort (a.begin(), a.end());
  int64_t ans = LLONG_MAX;
  do {
   debug (a);
   int64_t cur_ans = 0;
   int64_t N = n;
   int64_t E = e, H = h;
   for (int i = 0; i < 3; i++) {
    if (a[i].second == 1) {
     int64_t tt = min (N, E / 2);
     cur_ans += tt * a[i].first;
     N -= tt;
     E -= 2 * tt;
    } else if (a[i].second == 2) {
     int64_t tt = min (N, H / 3);
     cur_ans += tt * a[i].first;
     N -= tt;
     H -= 3 * tt;
    } else {
     int64_t tt = min (N, min (E, H));
     cur_ans += tt * a[i].first;
     N -= tt;
     E -= tt;
     H -= tt;
    }
   }
   if (N == 0) {
    ans = min (ans, cur_ans);
   } else {
    assert (E < 2 && H < 3);
   }
  } while (next_permutation (a.begin(), a.end()));
  if (ans == LLONG_MAX) ans = -1;
  cout << ans << '\n';
 }
 return 0;
}
