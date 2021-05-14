#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n; 
  vector<int> a, b;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   if (i % 2 == 0) a.push_back (x);
   else b.push_back (x);
  }

  auto f = [&] (vector<int> A) -> long long {
   long long sum = 0;
   int N = (int) A.size();
   for (int i = 0; i < N; i++) {
    sum += A[i];
   }
   return sum;
  };

  cout << max (f (a), f (b)) << '\n';
 }
 return 0;
}
