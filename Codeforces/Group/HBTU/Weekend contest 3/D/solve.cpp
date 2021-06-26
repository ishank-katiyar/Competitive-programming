#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
 #include <bits/debugger.hpp>
 #define __int64 __int64_t
#else 
 #define debug(a...) //
#endif

const int maxa = 1e7 + 1;
const int maxn = 1e5 + 1;
vector<int> sf(maxa , -1);
vector<bool> is_prime(maxa , true);
map<int , set<int>> inde;

void seive() {
 for(int i = 2; i < maxa; i++) {
  if(is_prime[i]) {
   for(int j = i; j < maxa; j += i) {
    sf[j] = i;
    if(j != i) is_prime[j] = false;
   }
  }
 }
}

vector<int> p_f(int n) {
 vector<int> ret;
 while(sf[n] != -1) ret.emplace_back(sf[n]) , n /= sf[n];
 return ret;
}

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 seive();
 int n , m;
 cin >> n >> m;
 vector<int> a(n) , b(m);
 for(int i = 0; i < n; i++) {
  int x;
  cin >> x;
  a[i] = x;
  vector<int>  p = p_f(x);
  for(int& k : p) {
   inde[k].insert(i);
  }
 }
 for(int i = 0; i < m; i++) {
  int x;
  cin >> x;
  vector<int> p = p_f(x);
  for(int& k : p) {
   if((int) inde[k].size() > 0) {
    int idx = (int) *inde[k].begin();
    a[idx] /= k;
    x /= k;
    if(a[idx] % k) {
     inde[k].erase(idx);
    }
   }
  }
  b[i] = x;
 }
 cout << n << ' ' << m << '\n';
 for(int& i : a) cout << i << ' ';
 cout << '\n';
 for(int& i : b) cout << i << ' ';
 cout << '\n'; 
 return 0;
}
