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
  int l; 
  cin >> l;
  vector<int> a;
  a.push_back(0);
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   a.push_back(x);
  }
  a.push_back(l);
  n += 2;
  vector<long double> time1(n);
  int speed = 1;
  for (int i = 1; i < n; i++) {
   long double dist = a[i] - a[i - 1];
   long double x = dist / speed;
   time1[i] += time1[i - 1] + x;
   speed++;
  }
  vector<long double> time2(n);
  speed = 1;
  for (int i = n - 2; i >= 0; i--) {
   long double dist = a[i + 1] - a[i];
   long double x = dist / speed;
   time2[i] += time2[i + 1] + x;
   speed++;
  }
  debug(time1, time2);
  reverse(time2.begin(), time2.end());
  speed = 1;
  long double s1 = 1, s2 = 0;
  long double dist = 0;
  long double ans = 0.0;
  for (int i = 1; i < n; i++) {
   auto it = lower_bound(time2.begin(), time2.end(), time1[i]);
   int idx = it - time2.begin();
   if (time2[idx] != time1[i]) idx--; 
   assert (idx >= 0);
   idx = n - idx - 1;
   debug(i, idx);
   if (i == idx && time1[i] == time2[n - idx - 1]) {
    ans = time1[i];
    break;
   }
   if (idx <= i) {
    debug(i, i + 1);
    dist = a[i] - a[i - 1];
    idx = n - idx - 1;
    i--;
    long double extra = time1[i] - time2[n - i - 2];
    debug(extra);
    ans = time1[i];
    s1 = speed;
    speed = 1;
    speed = n - i - 1;
    s2 = speed;
    dist -= (extra * s2);
    assert (dist >= 0.000000);
    break;
   }
   speed++;
  }

  debug(dist, s1, s2);
  ans += dist / (s1 + s2); 
  cout << fixed << setprecision(10) << ans << '\n';
 }
 return 0;
}
