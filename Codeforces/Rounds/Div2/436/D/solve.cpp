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
 int n;
 cin >> n;
 vector<int> a(n);
 map<int, int> mp;
 multiset<int> s;
 for (int i = 1; i <= n; i++) s.insert (i);
 for (auto& i: a) cin >> i, mp[i]++;
 for (auto& i: a) {
  if (s.count (i)) s.erase(i);
 }
 cout << (int) s.size() << '\n';
 map<int, int> compul;
 for (int i = 0; i < n; i++) {
  debug(i, s, compul);
  assert (mp[a[i]] > 0);
  if (compul[a[i]]) {
   debug("got in comp");
   mp[a[i]]--;
   a[i] = *s.begin();
   s.erase(s.begin());
  }
  else {
   if (mp[a[i]] == 1) {
    debug("i have freq 1");
    mp[a[i]]--;
    continue;
   }
   else {
    if (a[i] < *s.begin()) {
     debug("i will get ingnored");
     compul[a[i]] = true;
    }
    else {
     debug("i will get changed");
     mp[a[i]]--;
     a[i] = *s.begin();
     s.erase(s.begin());
    }
   }
  }
 }
 assert (s.empty() == true);
 for (auto& i: a) cout << i << ' ';
 cout << '\n';
 return 0;
}
