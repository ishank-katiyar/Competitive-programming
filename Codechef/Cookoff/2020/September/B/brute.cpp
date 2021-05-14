#include <bits/stdc++.h>
#define ll long long int
using namespace std;

static const auto fast_io = [] {
 ios_base::sync_with_stdio(false); 
 cin.tie(nullptr); cout.tie(nullptr); 
 return nullptr;
}();

const  int mod= 1e9 +7;
ll mpower(ll a , ll b) {
 ll res=1;a%=mod;
 while(b) {
  if(b & 1) res *= a, res%=mod;
  a *= a, a%=mod;
  b >>= 1;
 }
 return res;
}

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
   return res;
}
vector<ll> fact(1e5+1,1);

void fillfact(){
  fact[0]=fact[1]=1;
  for(int i=1;i<= 1e5; i++)
  fact[i]=(i*fact[i-1])%mod;
}

ll nCr(int f,int hf){
 ll a = fact[f];
 ll b= fact[hf];
 b= (b%mod)*(b%mod);
 b%= mod;
 b= mpower(b,mod-2);
 ll ans= ((a%mod)*(b%mod))%mod;
 return ans;
}

int main() {
    int t;
    ll n,k,l,count,sum, max;
    string s;
    char prev;
    cin >> t;
    while(t--){
        max = 0;
        vector<ll> v;
        v.push_back(0);
        count=-1;
        prev='0';
        sum=0;
        l=0;
        cin >> n >> k ;
        cin >> s;
        for(int i=0;i< (int) s.size();i++)
        {
         if(s[i]=='0') {
          ++l;
         }
          if(prev!=s[i]) {
           if (s[i] == '0' && i == 0)  {}
           else ++max;
          }
          if( prev=='0' && s[i]=='1'){
           count++;
           v.push_back(l-v[count]);
          }
         prev=s[i];
        }if(k==0)
         sum=l;
         else if(max-k>0 &&  v.size()>1){
           sort(v.begin(),v.end());
           for(int i= 1; i<=max-k;i++){
           sum+=v[i];
           }
         }
         cout << sum << endl;
        
    }
 return 0;
}
