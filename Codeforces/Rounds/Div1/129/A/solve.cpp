#include <bits/stdc++.h>

using namespace std;

template<class X, class Y>
X bpow(X a , Y b) {
 X res(1);
 while(b) {
  if(b % 2 == 1) res *= a;
  a *= a;
  b /= 2;
 }
 return res;
}

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 long long l, r;
 cin >> l >> r;
 auto f = [] (long long n) -> long long {
  if (n == 0) return 0;
  //if (n < 10) return n;
  int x = 0;
  long long N = n;
  while (N > 0) x++, N /= 10;
  long long ans = 0;
  for (int i = 1; i < x; i++) {
   if (i <= 2) ans += 9;
   else ans += bpow <long long, long long> (10, i - 2) * 9;
  }
  while (1) {
   string s = to_string(n);
   if (s[0] == s[(int) s.size() - 1]) break;
   n--;
  }
  if (n < bpow<long long> (10, x - 1)) {
   return ans;
  }
  int X = n % 10;
  assert (X > 0);
  string s = to_string(n);
  s.erase (s.begin());
  if (s.empty() == false) s.erase (--s.end());
  if (s.empty() == false) {
   long long dif = stoll(s);
   dif++;
   //cerr << dif << endl;
   assert (dif >= 0);
   ans += dif;
  }
  else ans++;
  ans += bpow <long long, long long> (10, (int) s.size()) * (X - 1);
  return ans;
 };
 //cerr << f(10) << endl;
 cout << f(r) - f(l - 1) << '\n';
 return 0;
}
