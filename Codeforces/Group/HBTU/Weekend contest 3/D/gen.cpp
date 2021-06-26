#include <bits/stdc++.h>
#include <bits/debugger.hpp>
#include <bits/print.hpp>
using namespace std;

const int maxa = 9999991;

bool is_prime(int n) {
 for(int i = 2; i <= sqrt(n); i++) if(n % i == 0) return false;
 return true;
}

int main() {
 /*
 while(maxa--) {
  if(is_prime(maxa)) {
   debug(maxa);
   return 0;
  }
 }
 */
 int n;
 cin >> n;
 vector<int> a(n , (int) 1e7);
 vector<int> b(n  ,1);
 print(n , n);
 print(a);
 print(b);
 return 0;
}
