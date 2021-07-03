#include <bits/stdc++.h>

using namespace std;

int64_t binpower(int64_t base, int64_t e, int64_t mod)
{
	int64_t result = 1;
	base %= mod;
	while (e)
	{
		if (e & 1)
			result = (__int128)result * base % mod;
		base = (__int128)base * base % mod;
		e >>= 1;
	}
	return result;
}

bool check_composite(int64_t n, int64_t a, int64_t d, int s)
{
	int64_t x = binpower(a, d, n);
	if (x == 1 || x == n - 1)
		return false;
	for (int r = 1; r < s; r++)
	{
		x = (__int128)x * x % n;
		if (x == n - 1)
			return false;
	}
	return true;
}

bool MillerRabin(int64_t n)
{ 
	if (n < 2)
		return false;

	int r = 0;
	int64_t d = n - 1;
	while ((d & 1) == 0)
	{
		d >>= 1;
		r++;
	}

	for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
	{
		if (n == a * int64_t(1))
			return true;
		if (check_composite(n, a, d, r))
			return false;
	}
	return true;
}

template <class X>
vector<X> trial_division3(X n)
{
	if (n <= 0)
	{
		return {};
	}
	vector<X> factorization;
	for (int d : {2, 3, 5})
	{
		if (n % d == 0)
			factorization.push_back(d);
		while (n % d == 0)
		{
			n /= d;
		}
	}
	static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
	int i = 0;
	for (X d = 7; d * d <= n; d += increments[i++])
	{
		if (n % d == 0)
			factorization.push_back(d);
		while (n % d == 0)
		{
			n /= d;
		}
		if (i == 8)
			i = 0;
	}
	if (n > 1)
		factorization.push_back(n);
	return factorization;
}

template <class X>
vector<X> prime_factors(X N)
{
	if (N < (int)smallest_factor.size())
	{
		vector<X> ret;
		while (N > 1)
		{
			X pp = smallest_factor[N];
			ret.push_back(pp);
			while (N % pp == 0)
				N /= pp;
		}
		return ret;
	}
	if (MillerRabin(N))
	{
		return {N};
	}
	const int64_t threshold = 1e10;
	if (N <= threshold)
	{
		return trial_division3(N);
	}
	X pp = brent(N);
	vector<X> ans = prime_factors(pp);
	for (auto &i : ans)
	{
		while (N % i == 0)
			N /= i;
	}
	vector<X> aa = prime_factors(N);
	for (auto &i : aa)
	{
		ans.push_back(i);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int64_t ans = 0;
	int t;
	cin >> t;
	while (t--)
	{
		int64_t N;
		cin >> N;
		auto P = prime_factors(N);
		ans += N;
		if (N == 1)
		{
			continue;
		}
		vector<int64_t> pp;
		for (auto &i : P)
		{
			int cnt = 0;
			while (N % i == 0)
				cnt += 1, N /= i;
			assert(cnt > 0);
			while (cnt--)
				pp.push_back(i);
		}
		sort(pp.begin(), pp.end());
		int64_t cur_ans = 1;
		int64_t mul = 1;
		for (int i = int(pp.size()) - 1; i >= 1; i--)
		{
			mul *= pp[i];
			cur_ans += mul;
		}
		ans += cur_ans;
	}
	cout << ans << '\n';
	return 0;
}
