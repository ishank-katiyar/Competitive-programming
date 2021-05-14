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
 const int X = 600;
 int test_case = 0;
 cin >> test_case;
 for (int ttt = 1; ttt <= test_case; ttt++) {
  cout << "Case #" << ttt << ": ";
  int n;
  cin >> n;
  vector<int> a (n);
  vector<int> b (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i] >> b[i];
  }
  sort (a.begin(), a.end());
  sort (b.begin(), b.end());
  int ans1 = INT_MAX;
  for (int cur_x = -X; cur_x <= X; cur_x++) {
   int cur_ans_h = 0;
   for (int i = 0; i < n; i++) {
    cur_ans_h += abs (a[i] - (cur_x + i));
   }
   ans1 = min (ans1, cur_ans_h);
  }
  int ans2 = INT_MAX;
  for (int i = 0; i < n; i++) {
   int xx = b[i];
   int cur_ans = 0;
   for (int j = 0; j < n; j++) {
    cur_ans += abs (b[j] - xx);
   }
   // debug (i, cur_ans);
   ans2 = min (ans2, cur_ans);
  }
  debug (ans1, ans2);
  cout << ans1 + ans2 << '\n';
 }
 return 0;
}
