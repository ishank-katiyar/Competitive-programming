#include <bits/stdc++.h>
#define ll long long int
using namespace std;

static const auto fast_io = []
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return nullptr;
}();

const int mod = 1e9 + 7;
ll mpower(ll a, ll b)
{
	ll res = 1;
	a %= mod;
	while (b)
	{
		if (b & 1)
			res *= a, res %= mod;
		a *= a, a %= mod;
		b >>= 1;
	}
	return res;
}

ll power(ll a, ll b)
{
	ll res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
vector<ll> fact(1e5 + 1, 1);

void fillfact()
{
	fact[0] = fact[1] = 1;
	for (int i = 1; i <= 1e5; i++)
		fact[i] = (i * fact[i - 1]) % mod;
}
ll pr[1000001] = {0};
void isprime()
{
	pr[0] = 1;
	pr[1] = 1;
	for (ll a = 2; a * a <= 1000001; a++)
	{
		if (!pr[a])
		{
			for (ll b = a * a; b < 1000001; b += a)
			{
				pr[b] = 1;
			}
		}
	}
}
ll nCr(int f, int hf)
{
	ll a = fact[f];
	ll b = fact[hf];
	b = (b % mod) * (b % mod);
	b %= mod;
	b = mpower(b, mod - 2);
	ll ans = ((a % mod) * (b % mod)) % mod;
	return ans;
}
vector<ll> parent;
vector<ll> ranks;

void make_sets(ll n)
{
	parent.clear();
	ranks.clear();
	ranks.resize(n);
	parent.resize(n);
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
		ranks[i] = 0;
	}
}
ll find_sets(ll v)
{
	if (parent[v] == v)
		return v;
	else
		return parent[v] = find_sets(parent[v]);
}

bool union_set(ll a, ll b)
{
	a = find_sets(a);
	b = find_sets(b);
	if (a != b)
	{
		if (ranks[a] < ranks[b])
			swap(a, b);
		else if (ranks[a] == ranks[b])
			ranks[a]++;

		parent[b] = a;
		return false;
	}
	else
		return true;
}
int main()
{
	ll t, n, m, time;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> time;
		vector<ll> p(n), a(m), k(m);
		for (int i = 0; i < n; i++)
			cin >> p[i];
		for (int i = 0; i < m; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> k[i];
		vector<pair<ll, ll>> maxmarks(m);
		for (int i = 0; i < m; i++)
		{
			maxmarks[i] = {k[i], a[i]};
		}
		sort(maxmarks.begin(), maxmarks.end(), [] (const pair<ll, ll> A, const pair<ll, ll> B) -> bool {
			if (A.first == B.first) return A.second > B.second;
			return A.first < B.first;
		});
		int marks = 0, timec = 0;
		for (int i = m - 1; i >= m / 2; i--)
		{
			marks += maxmarks[i].first;
			timec += maxmarks[i].second;
		}
		sort(p.begin(), p.end());
		int timeleft = time - timec;
		int ans = 0, count = 0;
		for (int i = 0; i < n; i++)
		{
			if (count + p[i] > timeleft)
				break;
			else
				count += p[i];
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}