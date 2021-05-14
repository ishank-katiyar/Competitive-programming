#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	 int n , m , k;
	 cin >> n >> m >> k;
	 vector<int> s , q;
	 int x;
	 for(int i = 0; i < n ; i++) cin >> x , s.push_back(x);
	 for(int i = 0; i < m ; i++) cin >> x , q.push_back(x);
	 sort(s.begin() , s.end());
	 sort(q.begin() , q.end());
	 int cnt = 0;
	 int idx1 = 0 , idx2 = 0;
	 while(1) {
	 	if(idx1 == n || idx2 == m) break;
	 	if(q[idx2] < s[idx1] - k) idx2++;
	 	else if(s[idx1] >= q[idx2] - k && s[idx1] <= q[idx2] + k) idx2++ , idx1++ , cnt++;
	 	else if(q[idx2] > s[idx1] + k) idx1++;
	 }
	 cout << cnt;
	 return 0;
}