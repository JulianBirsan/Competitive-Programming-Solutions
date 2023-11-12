#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<bool> vb;


struct dta{
	LL sum, pref, suff, ans;
};

dta seg[400005];
int arr[100005];

dta combine(dta l, dta r){
	dta res;
	res.sum = l.sum + r.sum;
	res.pref = max(l.pref,l.sum + r.pref);
	res.suff = max(r.suff, r.sum + l.suff);
	res.ans = max(max(l.ans,r.ans), l.suff + r.pref);
	return res;
}

dta make_dta(int val){
	dta res;
	res.sum = val;
	res.pref = res.suff = res.ans = val;
	return res;
}

void build(int l, int r, int at){
	if(l==r){
		seg[at] = make_dta(arr[l]);
		return;
	}
	int m = (l+r)/2;
	build(l,m,at*2);
	build(m+1,r,at*2+1);
	seg[at] = combine(seg[at*2],seg[at*2+1]);
}

void update(int at, int l, int r, int ind, int val){
	if(l==r){
		seg[at] = make_dta(val);
		return;
	}
	int m = (l+r)/2;
	if(ind <= m){
		update(at*2,l,m,ind,val);
	}
	else{
		update(at*2+1,m+1,r,ind,val);
	}
	seg[at] = combine(seg[at*2],seg[at*2+1]);
}

dta sum(int at, int l, int r, int segl, int segr){
	if(l>r){
		return make_dta(-MAXLN);
	}
	if(l == segl && r == segr){
		return seg[at];
	}
	int m = (segl + segr)/2;
	return combine(sum(at*2,l,min(r,m),segl,m),sum(at*2+1,max(l,m+1),r,m+1,segr));
}

int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i = 1; i <= n; i++){
		scanf("%d",&arr[i]);
	}
	build(1,n,1);
	char que;
	for(int i = 0; i < q; i++){
		cin >> que;
		if(que=='S'){
			int ind, x;
			scanf("%d %d",&ind,&x);
			update(1,1,n,ind,x);
		}
		else{
			int l,r;
			scanf("%d %d",&l,&r);
			dta out = sum(1,l,r,1,n);
			cout << out.ans << "\n";
		}
	}
}