#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n , m;
	scanf("%d %d" , &n , &m);
	long long int cnt = 0;
	auto get = [](int N , int m , int mod) -> int {
		return (N / m) + (int)((N % m) >= mod && mod); 
	};
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++) {
			if((i * i + j * j) % m == 0) {
				cnt += (long long int)get(n , m , i) * get(n , m , j);
			}
		}
	}
	printf("%I64d" , cnt);
	return 0;
}
