#include <bits/stdc++.h>

using namespace std;

int main() 
{
 vector<string> A;
 string S;
 while (getline(cin, S)) {
  A.push_back (S);
 }
 string Verdict = "_ok";
 if (static_cast <int> (A.size()) != 1) Verdict = "_wa";
 else {
  for (auto& i: A[0]) {
   if (i < '0' || i > '9') Verdict = "_wa";
  }
  int Sz = static_cast <int> (A[0].size());
  if (Sz < 1 || Sz > static_cast <int> (1e5)) Verdict = "_wa";
  if (A[0][0] == '0') Verdict = "_wa";
 }
 cout << Verdict;
 return 0;
}
