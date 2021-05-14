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
 int test_case;
 cin >> test_case;
 for (int tt = 1; tt <= test_case; tt++) {
  cout << "Case #" << tt << ": ";
  int w, n;
  cin >> w >> n;
  vector<int> a(w);
  for (auto& i: a) cin >> i;
  sort (a.begin(), a.end());
  vector<long long> pre(w);
  pre[0] = a[0];
  for (int i = 1; i < w; i++) pre[i] += pre[i - 1] + a[i];
  long long ans = LLONG_MAX;
  for (int i = 0; i < w; i++) {
   long long cur = 0;
   auto it = lower_bound (a.begin(), a.end(), a[i] - (n / 2));
   int l = it - a.begin();
   assert (l <= i);
   long long cnt = i - l + 1;
   long long pre_sum = 0;
   if (l == 0) pre_sum = pre[i];
   else pre_sum = pre[i] - pre[l - 1];
   cur += cnt * a[i] - pre_sum;
   it = upper_bound (a.begin(), a.end(), a[i] + (n / 2));
   int r = it - a.begin();
   r--;
   assert (a[r] <= (a[i] + (n / 2)));
   assert (r >= i);
   cnt = r - i + 1;
   if (i == 0) pre_sum = pre[r];
   else pre_sum = pre[r] - pre[i - 1];
   cur += pre_sum - cnt * a[i];
   debug(i, l, r);
   l--;
   if (l >= 0) {
    cnt = l + 1;
    pre_sum = pre[l];
    cur += pre_sum + cnt * (n - a[i]);
   }
   r++;
   if (r < w) {
    cnt = w - r;
    pre_sum = pre[w - 1] - pre[r - 1];
    pre_sum = cnt * n - pre_sum;
    cur += pre_sum + cnt * a[i];
   }
   debug(i, cur);
   ans = min (ans, cur);
  }
  cout << ans << '\n';
 }
 return 0;
}
