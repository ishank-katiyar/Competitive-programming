#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++)  scanf("%d" , &a[i]);
	int mn = *min_element(a.begin() , a.end());
	if(count(a.begin() , a.end() , mn) > 1) {
		puts("Still Rozdil");
		return 0;
	}
	int index = find(a.begin() , a.end() , mn) - a.begin();
	index++;
	printf("%d" , index);
	return 0;
}