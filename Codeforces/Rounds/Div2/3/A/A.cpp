#include "bits/stdc++.h"
using namespace std;

int main()
{
	string s;
	cin >> s;
	int x = (int) (s[0] - 'a');
	int y = (int) (s[1] - '0');
	cin >> s;
	int x0 = (int) (s[0] - 'a');
	int y0 = (int) (s[1] - '0');
	cout << max(abs(x - x0) , abs(y - y0)) << '\n';
	while (1)
	{
  	if (x == x0 && y == y0) break; 
  	if (x > x0) {x0 ++; cout << "L";} 
  	else if (x < x0) {x0--; cout << "R";} // otherwise, let's go left
  	if (y > y0) {y0 ++; cout << "D";} 
  	else if (y < y0) {y0--; cout << "U";}
  	cout << endl;
	}
	return 0;
}
