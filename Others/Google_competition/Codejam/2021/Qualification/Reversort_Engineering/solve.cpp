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
 for (int tt = 1; tt <= t; tt++) {
  int n, c;
  cin >> n >> c;
  auto ff = [] (vector<int> a) -> int {
   int N = static_cast <int> (a.size());
   int ans = 0;
   for (int i = 0; i < N - 1; i++) {
    int idx = i, ele = a[i];
    for (int j = i + 1; j < N; j++) {
     if (a[j]  < ele) {
      ele = a[j];
      idx = j;
     }
    }
    ans += (idx - i + 1);
    int ii = i;
    while (idx > ii) {
     swap (a[idx], a[ii]);
     idx--;
     ii++;
    }
   }
   return ans;
  };

  vector<int> a (n);
  for (int i = 0; i < n; i++) {
   a[i] = i + 1;
  }
  vector<int> ans;
  do {
   debug (a, ff(a));
   if (ff(a) == c) {
    ans = a;
   }
  } while (next_permutation (a.begin(), a.end()));
  cout << "Case #" << tt << ": ";
  if (ans.empty()) {
   cout << "IMPOSSIBLE" << '\n';
  } else {
   for (auto& i: ans) {
    cout << i << ' ';
   }
   cout << '\n';
  }
 }
 return 0;
}
