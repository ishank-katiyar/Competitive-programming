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

const int maxn = 1e6 + 1;
vector<int> prime;
vector<bool> is (maxn, true);

void seive () {
 is[0] = is[1] = false;
 for (int i = 2; i < maxn; i++) {
  if (is[i]) {
   prime.push_back (i);
   for (int j = 2 * i; j < maxn; j += i) {
    is[j] = false;
   }
  }
 }
}

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 seive();
 for (auto& P: prime) {
  if (P == 2) continue;
  map<long long, int> mp;
  for (long long i = 1; i < P; i++) {
   mp[(i * i) % P]++;
  }
  debug (P);
  for (auto& i: mp) {
   if (i.second != 2) {
    debug (P, "incorrect", i.first, i.second);
   }
   assert (i.second == 2);
  }
 }
 // map<int, int> mp;
 // const int P = 46349;
 // for (int i = 1; i < P; i++) {
 //  mp[(i * i) % P]++;
 // }
 // for (auto& i: mp) {
 //  if (i.second != 2) {
 //   debug (P, "incorrect", i.first);
 //  }
 //  assert (i.second == 2);
 // }

 return 0;
}
