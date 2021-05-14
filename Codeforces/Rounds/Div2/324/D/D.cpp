#include "bits/stdc++.h"
using namespace std;

bool is_prime(int n) {
	if(n == 1) return false;
	for(int i = 2; i <= (int) sqrt(n); i++) if(n % i == 0) return false;
	return true;
}

int main()
{
  int n;
  scanf("%d" , &n);
  int c = 0;
  vector<int> a;
  while(n > 0) {
  	if(is_prime(n)) {
  		a.emplace_back(n);	
  		break;
  	}
  	n--;
  	c++;	
  }
  if(c == 0) {
  	printf("1\n%d" , n);
  	return 0;
  }
  if(is_prime(c)) {
  	a.emplace_back(c);
  	printf("%d\n" , (int) a.size());
  	for(int& i : a) printf("%d " , i);
  	return 0;
  }
  for(int i = 1; i <= c; i++) {
  	if(is_prime(i) && is_prime(c - i)) {
  		a.emplace_back(i) , a.emplace_back(c - i);
  		printf("%d\n" , (int) a.size());
  		for(int& I : a) printf("%d ", I);
  		return 0;		
  	}
  } 
  assert(false);
  return 0;
}
