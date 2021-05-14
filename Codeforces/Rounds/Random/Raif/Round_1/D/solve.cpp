#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 vector<int> a(n + 1);
 for (int i = 1; i <= n; i++) cin >> a[i];
 vector<pair<int, int>> ans;
 //{{{
 //for (int i = n; i >= 1; i--) {
   //if (a[i] == 1) { s1.insert (row);
    //ans.emplace_back(i, row);
    //row++;
   //}
  //}
  //set<int> s2;
  //for (int i = n; i >= 1; i--) {
   //if (a[i] == 2) {
    //if (s1.empty() == true) {
     //cout << -1 << '\n';
     //return 0;
    //}
    //int x = *s1.begin();
    //s1.erase(s1.begin());
    //ans.emplace_back(i, x);
    //s2.insert (x);
   //}
  //}
  //for (int i = n; i >= 1; i--) {
   //if (a[i] == 3) {
    //if (s1.empty() == true && s2.empty() == true) {
     //cout << -1 << '\n';
     //return 0;
    //}
    //if (s1.empty() == false) {
     //int x = *s1.begin();
     //s1.erase (s1.begin());
     //ans.emplace_back(i, x);
    //}
    //if (s2.empty() == false) {
     //int x = *s2.begin();
     //s2.erase (s2.begin());
     //ans.emplace_back(i, x);
    //}
   //}
 //}
 //}}}
 set<int> s1;
 set<int> s2;
 set<int> s3;
 for (int i = n; i >= 1; i--) {
  if (a[i] == 1) {
   s1.insert (i);
   ans.emplace_back(i, i);
  }
  if (a[i] == 2) {
   if (s1.empty() == true) {
    cout << -1 << '\n';
    return 0;
   }
   int x = *s1.begin();
   s1.erase (s1.begin());
   assert (x > i);
   ans.emplace_back(i, x);
   s2.insert (i);
  }
  if (a[i] == 3) {
   if (s1.empty() == true && s2.empty() == true && s3.empty() == true) {
    cout << -1 << '\n';
    return 0;
   }
   if (s3.empty() == false) {
    int x = *s3.begin();
    s3.erase (s3.begin());
    assert (x > i);
    ans.emplace_back(i, i);
    ans.emplace_back(x, i);
    s3.insert (i);
   }   
   else if (s2.empty() == false) {
    int x = *s2.begin();
    s2.erase (s2.begin());
    assert (x > i);
    ans.emplace_back (i, i);
    ans.emplace_back (x, i);
    s3.insert (i);
   }
   else {
    int x = *s1.begin();
    s1.erase (s1.begin());
    assert (x > i);
    ans.emplace_back (i, i);
    ans.emplace_back (x, i);
    s3.insert (i);
   }
  }
 }
 assert ((int) ans.size() <= 2 * n);
 cout << (int) ans.size() << '\n';
 for (auto& i:ans) cout << i.second << ' ' << i.first << '\n';
 return 0;
}
