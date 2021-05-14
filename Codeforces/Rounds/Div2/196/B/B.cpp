#include "bits/stdc++.h"
using namespace std;

int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
    int x = b * c;
    int y = a * d;
    if (x > y) swap(x, y);
    x = y - x;
    int z = __gcd(x, y);
    x /= z; y /= z;
    printf("%d/%d", x, y);
    return 0;
}