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

string to_string(vector<bool> v) {
 bool first = true;
 string res = "{";
 for (int i = 0; i < static_cast<int>(v.size()); i++) {
  if (!first) {
   res += ", ";
  }
  first = false;
  res += to_string(v[i]);
 }
 res += "}";
 return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
 string res = "";
 for (size_t i = 0; i < N; i++) {
  res += static_cast<char>('0' + v[i]);
 }
 return res;
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

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  int n;
  cin >> n;
  vector<int> a;
  int cur = 0;
  while(n--) {
   int x;
   cin >> x;
   if(x == 0) cur++;
   else {
    if(cur > 0) a.push_back(cur);
    cur = 0;
   }
  }
  assert(cur == 0);
  sort(a.rbegin(), a.rend());
  //assert(a.back() != 0 && a[0] != 0);
  debug(a);
  if((int) a.size() == 0) {
   cout << "No\n";
  }
  else if((int) a.size() == 1) cout << (a[0] % 2 ? "Yes\n" : "No\n");
  else if((int) a.size() > 1) {
   if(a[0] % 2 == 0) cout << "No\n";
   else if(a[1] * 2 >= a[0]) cout << "No\n";
   else cout << "Yes\n";
   //if(a[0] == a[1]) cout << "No\n";
  }
 }
 return 0;
}
