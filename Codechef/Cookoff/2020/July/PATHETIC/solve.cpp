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

vector<ll> b = {13082761331670030, 245945384599471, 733735936};

void solve() {
 int n;
 cin >> n;
 vector<vector<int>> adj(n+1);
 int m = n-1;
 while(m--) {
  int x, y;
  cin >> x >> y;
  adj[x].push_back(y);
  adj[y].push_back(x);
 }
 vector<ll> level(n+1);
 vector<ll> ans(n+1); 
 vector<bool> used(n+1);
 queue<int> q;
 q.push(1);
 used[1] = true;
 level[1] = 1;
 ans[1] = b[0];
 while(q.empty() == false) {
  int u = q.front();
  q.pop();
  for(int& v: adj[u]) {
   if(used[v] == false) {
    used[v] = true;
    q.push(v);
    level[v] = level[u] + 1;
    ans[v] = b[level[v]-1];
   }
  }
 }
 for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
 cout << '\n';
}

int main()
{
 b[1] *= 6;
 b[2] *= 3;
 //vector<ll> a = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
 ////vector<ll> a = {53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
 //vector<ll> b = {13082761331670030, 245945384599471, 716539};
 //vector<ll> b = {13082761331670030, 245945384599471, 733735936};
 //ll ret = 1;
 ll mx = 2e18;
 //debug(mx);
 for(auto& i: b) {
  assert(i <= mx);
 }
 int t;
 cin >> t;
 while(t--) solve();
 return 0;
}
