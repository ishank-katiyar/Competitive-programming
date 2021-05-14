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
  int n, q;
  cin >> n >> q;
  vector<int> aa (n);
  for (int i = 0; i < n; i++) {
   cin >> aa[i];
  }
  map <long long, long long> mp;

  function<void (vector<int>)> f = [&] (vector<int> a) {
   debug (a);
   mp[accumulate (a.begin(), a.end(), 0LL)]++;
   debug ((int) mp.size());
   if ((int) a.size() == 1) {
    return;
   }
   int mid = *max_element (a.begin(), a.end()) + *min_element (a.begin(), a.end());
   mid /= 2;
   vector<int> A, B;
   for (auto& i: a) {
    if (i <= mid) A.push_back (i);
    else B.push_back (i);
   }
   if (a == A || a == B) return;
   if (A.empty() == false) f (A);
   if (B.empty() == false) f (B);
  };

  f (aa);

  while (q--) {
   long long s;
   cin >> s;
   if (mp.count (s)) cout << "Yes" << '\n';
   else cout << "No" << '\n';
  }

 }
 return 0;
}
