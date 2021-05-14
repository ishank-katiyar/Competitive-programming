#include <bits/stdc++.h>
//<------------PB-DS-------------->
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//<------------------------------->
using namespace std;
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define in(n) cin>>n
#define vc vector
#define vci vector<int>
#define vcl vector<long int>
#define vcll vector<long long int>
#define fs first
#define sec second
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define all(v) v.begin(),v.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define MOD (ll)998244353 
#define PI 3.14159265359
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
	
	int d,inter,s,v,f;
	cin>>d>>inter>>s>>v>>f;

	map<string,int>m;
	int count = 0;
	vc<vci> adj;
	rep(i,0,inter)
	{
		vci tempvec;
		adj.pb(tempvec);
	}

	rep(i,0,s)
	{
		int temp1,temp2;
		string tempstr;
		int temp3;
		cin>>temp1>>temp2>>tempstr>>temp3;
		m.insert(mp(tempstr,count));

		adj[temp2].pb(count);

		++count;

	}

	int sum[count]={0};

	rep(i,0,v)
	{
		int p;
		cin>>p;

		rep(z,0,p)
		{
			string tempstr;
			cin>>tempstr;
			++sum[m[tempstr]];
		}
	}
	vc<string>stringinfo(s);
	for(auto itr:m)
	{
		stringinfo[itr.second] = itr.first;
	}
	
	cout<<inter<<endl;

	rep(i,0,inter)
	{
		int max = 0;
		set<int> minpath;

		rep(j,0,adj[i].size())
		{
			if(sum[adj[i][j]]>sum[adj[i][max]])
			{
				max = j;

			}

			if(sum[adj[i][j]]==0)
				minpath.insert(j);
		}
		int val = 1;
		int othercount = 0;
		++othercount;
		int tempd = d;
		tempd-=val;

		rep(j,0,adj[i].size())
		{
			if(tempd<=0)
			break;
			if((int)j!=max&&minpath.find(j)==minpath.end())
			{
				--tempd;
				++othercount;
			}
		}
		cout<<i<<endl;
		cout<<othercount<<endl;
		tempd = d;
		cout<<stringinfo[adj[i][max]]<<" "<<min(tempd,val)<<endl;
		tempd-=val;
		rep(j,0,adj[i].size())
		{
			if(tempd<=0)
			break;
			if((int)j!=max&&minpath.find(j)==minpath.end())
			{
				cout<<stringinfo[adj[i][j]]<<" "<<1<<endl;
				--tempd;
			}
		}
		

	}
}
