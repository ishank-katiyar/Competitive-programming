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
int offshift = 0;
vector<pair<int, char>> ans;

void func(vector<int> a) {
 set<int> s(a.begin(), a.end());
 if((int) s.size() == 1 && (int) a.size() > 1) {
  cout << "NO" << '\n';
  exit(0);
 }
 while((int) a.size() != 1) {
  auto it = max_element(a.begin(), a.end());
  int ind = it - a.begin();
  int mx = *it;
  bool ok = true;
  vector<int> b;
  int n = (int) a.size();
  for(int i = 0; i < n; i++) {
   if(ok) {
    if(i > 0) {
     if(a[i] == mx && a[i-1] < mx) {
      b.back() = b.back() + mx;
      ok = false;
      ans.emplace_back(offshift + i+1, 'L');
      continue;
     }
    }
   }
   if(ok) {
    if(i < n-1) {
     if(a[i] == mx && a[i+1] < mx) {
      b.push_back(mx + a[i+1]);
      ok = false;
      ans.emplace_back(offshift + i+1, 'R');
      i++;
      continue;
     }
    }
   }
   b.push_back(a[i]);
  }
  assert((int) b.size() == n-1);
  a = b;
 }
}

int main()
{
 int n;
 cin >> n;
 vector<int> a(n);
 for(int& i: a) cin >> i;
 int m;
 cin >> m;
 vector<int> b(m);
 for(auto& i: b) cin >> i;
 while(b.empty() == false) {
  int x = b[0];
  b.erase(b.begin());
  int pre = 0;
  vector<int> aa;
  while(a.empty() == false) {
   pre += a[0];
   aa.push_back(a[0]);
   a.erase(a.begin());
   if(pre == x) break;
   if(pre > x) {
    cout << "NO" << '\n';
    return 0;
   }
  }
  if(a.empty() == true && b.empty() == false) {
   cout << "NO" << '\n';
   return 0;
  }
  if(a.empty() == false && b.empty() == true) {
   cout << "NO" << '\n';
   return 0;
  }
  if(pre != x) {
   cout << "NO" << '\n';
   return 0;
  }
  func(aa);
  //offshift += (int) aa.size();
  offshift++;
 }
 cout << "YES" << '\n';
 debug(ans);
 for(auto& i: ans) cout << i.first << ' ' << i.second << '\n';
 return 0;
}
