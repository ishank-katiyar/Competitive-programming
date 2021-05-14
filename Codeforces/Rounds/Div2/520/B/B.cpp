#include "bits/stdc++.h"
using namespace std;

int cnt = 0 , cnt_mul = 0;

bool check(int n) {
	for(int i = 2; i <= (int) sqrt(n); i++) {
		if(n % i) continue;
		int cnt1 = 0;
		while(n % i == 0) cnt1++ , n /= i;
		if(cnt1 != 1) return false;
	}
	return true;
}

int next_no(int n) {
	long long int an = n;	
	long long int mul = 1;
	for(int i = 2; i <= (int) sqrt(n); i++) {
		if(n % i) continue;
		int cnt1 = 0;
		while(n % i == 0) cnt1++ , n /= i;
		if(cnt1 & 1) mul *= i;
	}
	if(n != 1) mul *= n;
	if(mul != 1) cnt_mul++;
	an *= mul;
	n = (int) sqrt(an);
	cnt++;
	cerr << n << '\n';
	return n;
}

int main()
{
	int n;
	scanf("%d" , &n);
	while(check(n) == false) n = next_no(n);
	printf("%d %d", n , cnt + (cnt_mul ? 1:0));
	return 0;
}