#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int n, x;
        cin >> n >> x;
        int e=0, o=0;
        for(int i=0; i<n; i++) {
            int z;
            cin >> z;
            if(z&1) o++;
            else e++;
        }
        if(x&1) {
            bool canDo=false;
            for(int i=0; i<=min(e, x); i+=2) {
                int evens = i;
                int odds = x-i;
                if (o >= odds) {
                    canDo = true;
                    break;
                }
            }
            if (canDo) {
                cout << "Yes\n";
            } else cout << "No\n";
        } else {
            bool canDo=false;
            for(int i=1; i<=min(e, x); i+=2) {
                int evens = i;
                int odds = x-i;
                if (o >= odds) {
                    canDo = true;
                    break;
                }
            }
            if (canDo) {
                cout << "Yes\n";
            } else cout << "No\n";
        }
	}
	return 0;
}
