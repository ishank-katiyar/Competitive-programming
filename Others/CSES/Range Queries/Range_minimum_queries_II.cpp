#include "bits/stdc++.h"

using namespace std;

class Segment_Tree {
	vector<int> seg;
	public:
	Segment_Tree(vector<int> &a) {
		seg.assign(4 * (int) a.size() + 1 , 1e9 + 1);
		build(a , 1 , 1 , (int) a.size());
	}
	void build(vector<int> &a, int index , int l ,int r) {
		if(l == r) seg[index] = a[l - 1];
		else {
			int mid = (l + r) / 2;
			build(a , index * 2 , l , mid);
			build(a , index * 2 + 1 , mid + 1, r);
			seg[index] = min(seg[index * 2] , seg[index * 2 + 1]);  
		} 
	}
	int query(int index , int left , int right , int l , int r) {
		if(r < l) return 1e9 + 1;
		if(left == l && right == r) return seg[index];  
		int mid = (left + right) / 2;
		return min(query(index * 2 , left ,  mid , l , min(r , mid)) , query(index * 2 + 1, mid + 1, right , max(l, mid + 1) ,r));
	}
	void update(int index, int l, int r, int pos , int new_val) {
		if(l == r) seg[index] = new_val;
		else {
			int mid = (l + r) / 2;
			if(pos <= mid) update(index * 2 , l , mid , pos, new_val);
			else update(index * 2 + 1, mid + 1, r , pos , new_val);
			seg[index] = min(seg[index * 2] , seg[index * 2 + 1]);
		}
	} 
};

int main()
{
	int n , q;
	scanf("%d %d" , &n, &q);
	vector<int> ar(n);
	for(int i = 0; i < n; i++) scanf("%d" , &ar[i]);
	Segment_Tree seg(ar);
	while(q--) {
		int qr ,l , r;
		scanf("%d %d %d" , &qr , &l , &r);
		if(qr == 1) seg.update(1 , 1 , n , l , r); 	
		else printf("%d\n" , seg.query(1 , 1 , n , l ,r)); 
	}
	return 0;
}
