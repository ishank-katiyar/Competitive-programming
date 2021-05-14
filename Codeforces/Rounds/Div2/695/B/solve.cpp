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
  int n;
  cin >> n;
  vector<int> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  int sum = 0;

  auto f = [&] (int i) -> bool {
   if (i <= 0 || i >= n - 1) return false;
   assert (i > 0 && i < n - 1);
   if (a[i] > a[i - 1] && a[i] > a[i + 1]) return true;
   if (a[i] < a[i - 1] && a[i] < a[i + 1]) return true;
   return false;
  };

  vector<int> dp (n);
  for (int i = 0; i < n; i++) {
   if (f (i)) sum++;
   if (i > 0)dp[i] += dp[i - 1] + f (i);
  }

  auto get = [&] (int i, int j) -> int {
   if (j < i) return 0;
   if (i > 0) return dp[j] - dp[i - 1];
   return dp[j];
  };

  debug (sum);
  int ans = sum;

  for (int i = 0; i < n; i++) {
   int cur = 0;
   int tem = a[i];
   if (i > 0) a[i] = a[i - 1];
   if (f (i - 1)) cur++;
   if (f (i)) cur++;
   if (f (i + 1)) cur++;
   a[i] = tem;
   int cur_ans = get (0, i - 2) + cur + get (i + 2, n - 1);
   debug (i, cur_ans);
   ans = min (ans, cur_ans);

   tem = a[i];
   cur = 0;
   if (i < n - 1) a[i] = a[i + 1];
   if (f (i - 1)) cur++;
   if (f (i)) cur++;
   if (f (i + 1)) cur++;
   a[i] = tem;
   cur_ans = get (0, i - 2) + cur + get (i + 2, n - 1);
   debug (i, cur_ans);
   ans = min (ans, cur_ans);
  }
  debug (a);
  cout << ans << '\n';
  if (1) {

  }
  else {

  }
 }
 return 0;
}
