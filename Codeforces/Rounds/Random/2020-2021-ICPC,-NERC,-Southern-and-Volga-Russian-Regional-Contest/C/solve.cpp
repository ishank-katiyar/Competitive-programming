#include <bits/stdc++.h>

using namespace std;

class cmp {
public:
 bool operator () (const pair<int, int> A, const pair<int, int> B) const {
  if (A.first == B.first) return A.second > B.second;
  return A.first < B.first;
 }
};

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 const int maxn = static_cast<int> (5e5 + 1);
 vector<bool> used (maxn, false);
 deque<int> d;
 map<int, int> mp;
 multiset<pair<int, int>, cmp> ms;
 int customer_id = 0;
 int q;
 cin >> q;
 while (q--) {
  while (d.empty() == false && used[d.front()] == true) d.pop_front();
  int type;
  cin >> type;
  if (type == 1) {
   customer_id++;
   int money;
   cin >> money;
   d.push_back (customer_id);
   mp[customer_id] = money;
   ms.insert (make_pair (money, customer_id));
  } else if (type == 2) {
   int id = d.front();
   cout << id << '\n';
   d.pop_front();
   ms.erase (ms.find (make_pair (mp[id], id)));
  } else if (type == 3) {
   pair <int, int> p = *(--ms.end());
   ms.erase (--ms.end()); 
   cout << p.second << '\n';
   used [p.second] = true;
  } else {
   assert (false);
  }
 }
 return 0;
}
