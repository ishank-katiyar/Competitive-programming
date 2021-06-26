#include <bits/stdc++.h>
#include <bits/debugger.hpp>
#include <bits/print.hpp>
using namespace std;

const int maxn = 20;
const int maxa = 100;

int r() {
 return 1 + (rand() % maxa);
}

int nn() {
 return  1 + (rand() % maxn);
}

int main(int agrc , char* argv[])
{
 int seed = atoi(argv[1]);
 srand(seed);
 int n = nn();
 cout << n << ' ' << r() * r() << '\n';
 for(int i = 1; i <= n; i++) cout << r() << ' ';
 cout << '\n';
 return 0;
}
