#include "bits/stdc++.h"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;		
	cin >> s;
	set<int> st = {0};
	int cnt = 0;
	int rem = 0; 
	for(char i : s) {
		if(i == '0') {
			cnt++;
			st.clear();
			st.insert(0);
			rem = 0;
			continue;
		}
		else {
			rem = rem * 10 + (i - '0');
			rem %= 3;
			if(st.count(rem)) {
				cnt++;
				st.clear();
				st.insert(0);
				rem = 0;
			}
			else {
				st.insert(rem);
			}
		}
	} 	
	printf("%d" , cnt);
	return 0;
}