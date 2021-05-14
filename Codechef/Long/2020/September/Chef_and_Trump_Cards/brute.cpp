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
 reverse(res.begin(), res.end());
 return res;
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
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i: a) cin >> i;
  int ans = 0;
  int mx = *max_element(a.begin(), a.end());

  auto check = [&] (vector<int> A, vector<int> B) -> bool {
   int freA = count (A.begin(), A.end(), mx);
   int freB = count (B.begin(), B.end(), mx);
   return freA != freB;
  };

  for (int mask = 0; mask < (1 << n); mask++) {
   vector<int> A;
   vector<int> B;
   for (int i = 0; i < n; i++) {
    if ((mask >> i) & 1) B.push_back(a[i]);
    else A.push_back(a[i]);
   }
   debug(mask, bitset<3>(mask), A, B);
   ans += check(A, B);
  }
  cout << ans << '\n';
 }
 return 0;
}


//3
//1 2 3

//A = unset bit
//B = set bit

//0 = 000 =  
//1 = 001 = 
//2 = 010
//3 = 011
//4 = 100
//5 = 101
//6 = 110
//7 = 111
//[mask, bitset<3>(mask), A, B ] = [0 000 {1, 2, 3} {} ]
//[mask, bitset<3>(mask), A, B ] = [1 001 {2, 3} {1} ]
//[mask, bitset<3>(mask), A, B ] = [2 010 {1, 3} {2} ]
//[mask, bitset<3>(mask), A, B ] = [3 011 {3} {1, 2} ]
//[mask, bitset<3>(mask), A, B ] = [4 100 {1, 2} {3} ]
//[mask, bitset<3>(mask), A, B ] = [5 101 {2} {1, 3} ]
//[mask, bitset<3>(mask), A, B ] = [6 110 {1} {2, 3} ]
//[mask, bitset<3>(mask), A, B ] = [7 111 {} {1, 2, 3} ]


//001
//i = 0
 //mask = 001 b = 
//i = 1
 //mask = 00 a = 


//A = 1 2
//B = 3 4

//A = 1 2, B = 3 4, B = 4 3
//A = 2 1, B = 3 4, B = 4 3
