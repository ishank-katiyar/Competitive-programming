#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n; 
	scanf("%d" , &n);
	int an = n;
	vector<int> prime;
	vector<bool> is_prime(n + 1 , true);
	for(int i = 2; i <= n; i++) {
		if(is_prime[i]) {
			prime.emplace_back(i);
			for(int j = i * i; j <= n; j += i) is_prime[j] = false;
		}
	}
	vector<int> ans;
	for(int& i : prime) {
		int x = i;
		while(x <= an) ans.emplace_back(x) , x *= i;
	}
	printf("%d\n" , (int) ans.size());
	for(int& i : ans) printf("%d " , i);
	return 0;
}