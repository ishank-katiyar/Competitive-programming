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
 int n;
 cin >> n;
 vector<pair<int, int>> one, two;
 for (int i = 1; i <= n; i++) {
  int I = 1;
  int J = i;
  vector<pair<int, int>> cur;
  while (I <= n && J >= 1) {
   cur.push_back (make_pair (I, J));
   I += 1;
   J -= 1;
  }
  for (auto& j: cur) {
   ((1 + i) % 2 == 0 ? one : two).push_back (j);
  }
 }
 for (int i = 2; i <= n; i++) {
  int I = i;
  int J = n;
  vector<pair<int, int>> cur;
  while (I <= n && J >= 1) {
   cur.push_back (make_pair (I, J));
   I += 1;
   J -= 1;
  }
  for (auto& j: cur) {
   ((i + n) % 2 == 0 ? one : two).push_back (j);
  }
 }

 reverse (one.begin(), one.end());
 reverse (two.begin(), two.end());

 debug (one);
 debug (two);

 auto read = [] () -> int {
  int x;
  cin >> x;
  return x;
 };

 // for (int turn = 1; turn <= n * n; turn++) {
 //  int a = read ();
 //  if (1 != a && one.empty() == false) {
 // 
 //  } else if (2 != a && two.empty() == false) {
 // 
 //  } else {
 // 
 //  }
 // }
 
 while (one.empty() == false && two.empty() == false) {
  int a = read ();
  if (1 != a) {
   cout << 1 << ' ' << one.back().first << ' ' << one.back().second << endl;
   one.pop_back();
  } else if (2 != a) {
   cout << 2 << ' ' << two.back().first << ' ' << two.back().second << endl;
   two.pop_back();
  } else {
   assert (false);
  }
 }

 while (one.empty() == false) {
  int a = read();
  if (1 != a) {
   cout << 1 << ' ' << one.back().first << ' ' << one.back().second << endl;
   one.pop_back();
  } else if (3 != a) {
   cout << 3 << ' ' << one.back().first << ' ' << one.back().second << endl;
   one.pop_back();
  } else {
   assert (false);
  }
 }

 while (two.empty() == false) {
  int a = read();
  if (2 != a) {
   cout << 2 << ' ' << two.back().first << ' ' << two.back().second << endl;
   two.pop_back();
  } else if (3 != a) {
   cout << 3 << ' ' << two.back().first << ' ' << two.back().second << endl;
   two.pop_back();
  } else {
   assert (false);
  }
 }

 return 0;
}
