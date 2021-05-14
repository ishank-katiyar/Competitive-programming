#include <bits/stdc++.h>
using namespace std;

static const auto fast_io = [] {
 ios_base::sync_with_stdio(false); 
 cin.tie(nullptr); cout.tie(nullptr); 
 return nullptr;
}();

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd() {
 return uniform_int_distribution<int> (1, (int) 1e9) (rng);
}

template<class A> 
A rnd(A x, A y) {
 return uniform_int_distribution<A> (x, y) (rng);
}

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

template<class A, class B, class C>
string to_string(priority_queue<A, B, C> a) {
 vector<A> res;
 while(a.empty() == false) {
  res.push_back(a.top());
  a.pop();
 }
 reverse(res.begin(), res.end());
 return to_string(res);
}

template<class A>
string to_string(priority_queue<A> a) {
 vector<A> res;
 while(a.empty() == false) {
  res.push_back(a.top());
  a.pop();
 }
 reverse(res.begin(), res.end());
 return to_string(res);
}

template<class A>
string to_string(stack<A> a) {
 vector<A> res;
 while(a.empty() == false) {
  res.push_back(a.top());
  a.pop();
 }
 return to_string(res);
}

template<class A>
string to_string(queue<A> a) {
 vector<A> res;
 while(a.empty() == false) {
  res.push_back(a.front());
  a.pop();
 }
 return to_string(res);
}

vector<string> __vector_tuple;
template<int index, class... A>
struct print_tuple {
 auto operator() (tuple<A...> a) {
  __vector_tuple.push_back(to_string(get<index>(a)));
  print_tuple<index-1, A...>{}(a);
 }
};

template<class... A>
struct print_tuple<0, A...> {
 auto operator() (tuple<A...> a) {
  __vector_tuple.push_back(to_string(get<0>(a)));
 }
};

template<class... T>
string to_string(tuple<T...> a) {
 const int ttsz = tuple_size<decltype(a)>::value;
 print_tuple<ttsz-1, T...>{}(a);
 string __ss = to_string(__vector_tuple);
 __vector_tuple.clear();
 return __ss;
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

typedef long long int ll;

int bit(ll a) {
 return 64 - __builtin_clzll(a);
}

//ll value(ll a, ll b) {
 //ll a1 = 64 - __builtin_clzll(a);
 //ll b1 = 64 - __builtin_clzll(b);
 //debug(a1,a,b1,b);
 //return a * ((1LL << b1) - 1) + b * (1 - (1LL << a1));
//}

int main()
{
 //int n;
 //cin >> n;
 //vector<int> a(n);
 //for(auto& i: a) cin >> i;
 //for(int i = 0; i < n; i++) {
  //for(int j = 0; j < n; j++) {
    //cout << value(a[i], a[j]) << ' ';
  //}
  //cout << '\n';
 //}
 int t;
 cin >> t;
 while(t--) {
  int n;
  cin >> n;
  vector<ll> a(n);
  for(ll& i: a) cin >> i;
  vector<vector<ll>> b(32);
  ll mx = 0;
  for(ll& i: a) b[bit(i)].push_back(i);
  for(int i =0; i < 32; i++) {
   sort(b[i].begin(), b[i].end());
  }
  for(int i = 0; i < 32; i++) {
   for(int j = 0; j < 32; j++) {
    ll x1 = (1LL << j) - 1;
    ll y1 = 1 - (1LL << i);
    int sz1 = (int) b[i].size();
    int sz2 = (int) b[j].size();
    if(sz1 == 0 || sz2 == 0) continue;
    ll value = b[i][sz1-1] * x1 + b[j][0] * y1;
    mx = max(mx, value);
   }
  }
  cout << mx << '\n';
 }
 return 0;
}
