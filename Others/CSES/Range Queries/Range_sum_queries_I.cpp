#include "bits/stdc++.h"

using namespace std;

class Segment_Tree {
	vector<long long int> seg;
	public:
	Segment_Tree(vector<int> &a) {
		seg.assign(4 * (int)a.size() + 1, 0);
		build(a , 1 , 1 , (int)a.size());
	}  	
	void build(vector<int> &a , int index , int left , int right) {
		if(left == right) seg[index] = a[left - 1];
		else {
			int mid = (left + right) / 2;
			build(a , index * 2, left , mid);
			build(a , index * 2 + 1 , mid + 1 , right);
			seg[index] = seg[index * 2] + seg[index * 2 + 1];
		}
	}	
	long long int query(int index ,int seg_l , int seg_r , int l , int r) {
		if(r < l) return 0;
		if(l == seg_l && r == seg_r) return seg[index];
		int mid = (seg_l + seg_r) / 2;
		return query(index * 2 , seg_l , mid , l , min(r , mid)) + query(index * 2 + 1, mid + 1 , seg_r , max(l , mid + 1) ,r);	
	}
};

int main()
{
	int n , q;
	scanf("%d %d" , &n , &q);
	vector<int> ar(n);
	for(int i = 0; i < n; i++) scanf("%d" ,&ar[i]);
	Segment_Tree seg(ar);
	while(q--) {
		int l , r;
		scanf("%d %d" , &l , &r);
		printf("%lld\n" , seg.query(1 , 1 , n , l , r)); 	
	} 	
	return 0;
}
