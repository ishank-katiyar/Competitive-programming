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
  long long int a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  int cur = 0;
  int cur1 = 0;
  vector<long long int> A;
  vector<long long int> B;
  for (int i = 0; i < n; i++) {
   if (s[i] == '0') {
    if (cur1 > 0) B.push_back(cur1);
    cur1 = 0;
    cur++;
   }  
   else {
    if (cur > 0) A.push_back(cur);
    cur = 0;
    cur1++;
   }
  }
  A.push_back(cur);
  debug(A, B);
  long long int ans = 0;
  if ((int) A.size() == 1) {
   ans = a * n + b * (n + 1);
   cout << ans << '\n';
   continue;
  }
  long long int last = A.back();
  A.pop_back();
  ans += a * (last + 1) + b * last;
  debug(ans);
  long long int first = *A.begin();
  A.erase(A.begin());
  ans += a * (first + 1) + b * first;
  debug(ans);
  for (auto& i: A) {
   if (i == 1) {
    ans += a;
   }
   else {
    long long int x = i - 2;
    ans += min (a * (x + 2) + 2 * b * (1 + x), a * (x + 4) + b * (x + 1));
   }
  }
  debug(ans);
  for (auto& i: B) {
   ans += a * i + 2 * b * (i + 1);
  }
  cout << ans << '\n';
 }
 return 0;
}
