#include "bits/stdc++.h"
using namespace std;

bool is_prime(int n) {
	for(int i = 2; i <= (int) sqrt(n); i++) if(n % i == 0) return false;
	return true;
}

int main()
{
	int n;
	scanf("%d" , &n);
	vector<pair<int , int>> ans;
	for(int i = 1; i <= n - 1; i++) ans.emplace_back(i , i + 1);
	ans.emplace_back(n , 1);
	int m = n;
	int x = 1;
	while(1) {
		if(is_prime(m)) {
			break;
		}
		else {
			ans.emplace_back(x , x + n / 2);
			x++;
			m++;	
		}
	}
	printf("%d\n" , (int) ans.size());
	for(auto& i : ans)  printf("%d %d\n" , i.first , i.second);
	return 0;
}