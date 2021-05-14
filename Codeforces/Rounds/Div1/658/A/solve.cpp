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
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  deque <char> d;
  for (auto& i: a) {
   d.push_back (i);
  }

  auto invert = [] (char ch) -> char {
   if (ch == '0') {
    return '1';
   }
   return '0';
  };

  bool forward = false;
  vector<int> ans;
  int cnt_invert = 0;
  for (int i = n - 1; i >= 1; i--) {
   // debug (i, d);
   if (forward == true) {
    if (cnt_invert % 2 == 1) {
     d.front() = invert (d.front());
    }
    if (d.front() == b[i]) {
     d.pop_front();
    } else {
     bool a1 = cnt_invert % 2 == 1 ? invert(d.back()) != b[i] : d.back() != b[i];
     if (a1 == false) {
      ans.push_back (1);
     }
     if (cnt_invert % 2 == 1) {
      d.front() = invert (d.front());
     }
     cnt_invert += 1;
     forward ^= 1;
     d.pop_back();
     ans.push_back (i + 1);
    }
   } else {
    if (cnt_invert % 2 == 1) {
     d.back() = invert (d.back());
    }
    if (d.back() == b[i]) {
     d.pop_back();
    } else {
     bool a1 = cnt_invert % 2 == 1 ? invert(d.front()) != b[i] : d.front() != b[i];
     if (a1 == false) {
      ans.push_back (1);
     }
     if (cnt_invert % 2 == 1) {
      d.back() = invert (d.back());
     }
     cnt_invert += 1;
     forward ^= 1;
     d.pop_front();
     ans.push_back (i + 1);
    }
   }
  }
  debug (d);
  if (cnt_invert % 2 == 1) {
   if (invert(d.front()) != b.front()) {
    ans.push_back (1);
   }
  } else {
   if (d.front() != b.front()) {
    ans.push_back (1);
   }
  }
  assert (static_cast <int> (ans.size()) <= 2 * n);
  cout << static_cast <int> (ans.size()) << ' ';
  for (auto& i: ans) {
   cout << i << ' ';
  }
  cout << '\n';
 }
 return 0;
}
