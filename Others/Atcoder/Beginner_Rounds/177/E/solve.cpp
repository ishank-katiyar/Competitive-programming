#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;
bitset<maxn> prime;
vector<int> sf(maxn);

void seive() {
 prime.set();
 prime[0] = prime[1] = false;
 for(int i = 2; i < maxn; i++) {
  if(prime[i]) {
   sf[i] = i;
   for(int j = 2 * i; j < maxn; j += i) {
    sf[j] = i;
    prime[j] = false;
   }
  }
 }
}

vector<int> c(maxn);

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 seive();
 int n;
 cin >> n;
 vector<int> a(n);
 int gd = 0;
 for(auto& i: a) {
  cin >> i, gd = __gcd(gd, i);
  int x = i;
  while(x != 1) {
   int ss = sf[x];
   c[ss]++;
   while(x % ss == 0) x /= ss;
  }
 }
 bool ok = true;
 for(int i = 2; i < maxn; i++) ok &= (c[i] <= 1);
 if(ok) {
  cout << "pairwise coprime\n";
 }
 else if(gd == 1) cout << "setwise coprime\n";
 else cout << "not coprime";
 return 0;
}
