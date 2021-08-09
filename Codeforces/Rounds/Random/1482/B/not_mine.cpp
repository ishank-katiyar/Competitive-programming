#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#pragma GCC optimize ("-O3")
#define ll long long  int
#define all(x) (x).begin(), (x).end()
using ld = long double;
const ll mod = 1000000007;
const ll inf = 1e9;
const ll rk = 256;
const ld PI = 3.141592653589793;
#define pb push_back
#define mp make_pair
#define vc vector
#define fs first
#define sec second
// #define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define all(x) (x).begin(), (x).end()
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define print(a) for(auto j:a) {cout<<j<<",";} cout << "\n";
#define endl '\n'
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
// getting string line
// getline(cin,word);
// -> priority_queue < int > pq; // max_heap
// -> priority_queue < int , vector < int > , greater < int > > pq; // min_heap


ostream & operator << (ostream & os, pair <ll, ll> const& x) {
    os << x.first << "," << x.second;
    return os;
}

template <class T>
ostream & operator << (ostream & os, vector <T> const& x) {
    os << "{ ";
    for(auto& y : x) os << y << " ";
    return os << "}";
}

template <class T>
ostream & operator << (ostream & os, set <T> const& x) {
    os << "{ ";
    for(auto& y : x) os << y << " ";
    return os << "}";
}

template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x) os << y << " ";
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
    return os << "[ " << p.first << ", " << p.second << "]" ;
}

struct Triplet{
    ll x,y,z;
};

ll modularexpo(ll x,ll n,ll mod){
    ll res = 1;
    while(n>0){
        if(n%2==1){
            res = (res*x)%mod;
        }
        x = (x*x);
        n = n/2;
    }
    return res;
}



int main(){
    FastIO;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n==1 || n==2){
            cout<<0<<endl;
            continue;
        }
        ll f = 0;
        for(ll i=1;i<n;i++){
            if(arr[i]!=arr[i-1]){
                f = 1;
            }
        }
        if(f==0){
            cout<<0<<endl;
            continue;
        }
        ll inc = 1e10, dec = 1e10;
        ll can = 1;
        ll a = -1,b = -1;
        for(ll i=1;i<n;i++){
            ll val = arr[i]-arr[i-1];
            if(val>0){
                if(inc==1e10){
                    inc = val;
                }
                if(inc!=val){
                    can = 0;
                    break;
                }
            }
            else if(val<0){
                if(dec==1e10){
                    a = arr[i-1];
                    b = arr[i];
                    dec = val;
                }
                if(dec!=val){
                    can = 0;
                    break;
                }
            }
            else{
                can = 0;
            }
        }
        if(can==0){
            cout<<-1<<endl;
        }
        else{
            if(dec==1e10){
                cout<<0<<endl;
            }
            else if(inc==1e10){
                cout<<0<<endl;
            }
            else{
                ll c = inc;
                ll val = inc;
                val-=b;
                if(val<0){
                    cout<<-1<<endl;
                }
                else{
                    ll m = a+val;
                    ll s = arr[0];
                    ll f = 0;
                    for(ll i=1;i<n;i++){
                        s = (s+c)%m;
                        if(s!=arr[i]){
                            f = 1;
                            break;
                        }
                    }
                    if(f==1){
                        cout<<-1<<endl;
                    }
                    else{
                        cout<<m<<" "<<c<<endl;
                    }
                }
            }
        }
    }
    // cout<<"Case #"<<tc+1<<": "<<func(0,2)<<endl;
    return 0;
}