#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
 #define __int64 __int64_t
#else 
 #define debug(a...) //
#endif

const int maxa = 5e6 + 1;
vector<bool> is_prime(maxa , true);
vector<int> c(maxa , 0);

int p(int j , int i) {
 int ret = 0;
 while(j % i == 0) ret++ , j /= i;
 return ret;
}

void seive()
{
 is_prime[1] = false;
 for(int i = 2; i < maxa; i++) {
  if(is_prime[i]) {
   for(int j = i; j < maxa; j += i) {
    c[j] += p(j , i);
    if(j != i) is_prime[j] = false;
   }
  }
 }
 for(int i = 1; i < maxa; i++) c[i] += c[i - 1]; 
}

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 seive();
 int t;
 cin >> t;
 while(t--) {
  int a , b;
  cin >> a >> b;
  cout << c[a] - c[b] << '\n';
 }
 return 0;
}
