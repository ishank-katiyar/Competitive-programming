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
  vector<int> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  if (n == 1) {
   cout << -1 << '\n';
   continue;
  }

  sort (a.rbegin(), a.rend());

  auto f = [&] (int mid) -> bool {
   int cnt = 0;
   int sum = 0;
   for (int i = 0; i < mid; i++) {
    cnt += (a[i] >= k);
    sum += a[i];
   }
   sum -= a[0];
   if (cnt > 1) return true;
   if (cnt == 1) {
    if (sum >= k) return true;
    return false;
   }
   sum += a[0];
   assert (cnt == 0);
   vector<int> dp (2 * k + 1, 0);
   dp[0] = 1;
   for (int i = 0; i < mid; i++) {
    for (int j = 2 * k; j >= 0; j--) {
     if (j + a[i] <= 2 * k && dp[j] > 0) dp[j + a[i]]++;
    }
   }
   bool ok = false;
   for (int i = k; i <= 2 * k; i++) {
    ok |= (i >= k && sum - i >= k && dp [i] > 0);
   }
   debug (mid, dp, sum, ok);
   return ok;
  };

  int low = 2, high = n;
  while (low < high) {
   int mid = (low + high) / 2;
   if (f (mid) == false) low = mid + 1;
   else high = mid;
  }
  if (f (low) == false) low = -1;
  cout << low << '\n';
 }
 return 0;
}
