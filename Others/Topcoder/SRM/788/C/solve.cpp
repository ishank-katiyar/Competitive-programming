#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
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

#else 
 #define debug(...) 

#endif

typedef long long int ll;

class SquareCityWalking {
public:
  int n = 0;
  vector<vector<int>> grid;
  vector<vector<int>> used;
  bool dfs(int r, int c, int gd) {
   if(used[r][c] == 1) return false;
   used[r][c] = 1;
   debug(r,c, gd);
   if(grid[r][c] % gd) {
    used[r][c] = 0;
    return  false;
   }
   if(r == n-1 && c == n-1) {
    used[r][c] = 0;
    return  true;
   }
   bool f1 = false, f2 = false, f3 = false, f4 = false;
   if(r-1 >= 0) f1 = dfs(r - 1, c, gd);
   if(r+1 < n) f2 = dfs(r + 1, c, gd);
   if(c-1 >= 0) f3 = dfs(r, c - 1, gd);
   if(c+1 < n) f4 = dfs(r, c + 1, gd);
   used[r][c] = 0;
   if(f1 || f2 || f3 || f4) return true;
   return false;
  }
  int largestGCD(int N, vector <int> A) {
    n = N;
    grid.assign(n, vector<int>(n));
    used.assign(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) grid[i][j] = A[i*N+j];
    debug(n, grid);
    int ret = 0;
    for(int i = 1; i <= 100; i++) if(dfs(0,0,i)) {
     debug(used);
     ret = i;
    }
    return ret;
  }
};

#ifdef LOCAL
int main()
{
 SquareCityWalking s;
 int n = 3;
 vector<int> A = { 96, 42, 45, 32, 36, 27, 40, 54, 84 };
 cout << s.largestGCD(n,A) << '\n';;
 return 0;
}
#endif
