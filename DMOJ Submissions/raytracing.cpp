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
typedef pair<string,int> psi;

vector<vi> ST;
int arr[40000];

vi merge(vi a, vi b){
	int i,j; i=j=0;
	vi out;
	while(i<a.size()||j<b.size()){
		if(i==a.size()){
			out.push_back(b[j]); j++;
		}
		else if(j==b.size()){
			out.push_back(a[i]); i++;
		}
		else if(a[i]<b[j]){
			out.push_back(a[i]);
			i++;
		}
		else{
			out.push_back(b[j]);
			j++;
		}
	}
	return out;
}

void build(int v,int l,int r){
	if(l==r){
		ST[v].push_back(arr[l]);
		return;
	}
	int m=(l+r)>>1;
	build(v<<1,l,m);
	build((v<<1)+1,m+1,r);
	ST[v]=merge(ST[v<<1],ST[(v<<1)+1]);
}

void update(int v,int l,int r,int ind,int val,int old){
	if(l>ind||r<ind)return;
	if(l==r){
		ST[v][0]=val;
		return;
	}
	int m=(l+r)>>1;
	update(v<<1,l,m,ind,val,old);
	update((v<<1)+1,m+1,r,ind,val,old);
	int place=lower_bound(ST[v].begin(),ST[v].end(),val)-ST[v].begin();
	ST[v].insert(ST[v].begin()+place,val);
	int rem=lower_bound(ST[v].begin(),ST[v].end(),old)-ST[v].begin();
	ST[v].erase(ST[v].begin()+rem);
}

int query(int v,int l,int r,int lq,int rq,int a,int b){
	if(lq>rq)return 0;
	if(l>=lq&&r<=rq){
		int f=lower_bound(ST[v].begin(),ST[v].end(),a)-ST[v].begin();
		int c=upper_bound(ST[v].begin(),ST[v].end(),b)-ST[v].begin();
//		cout<<"array: ";
//		for(auto u:ST[v]) cout<<u<<" ";
//		cout<<"\n";
//		cout<<a<<" "<<b<<"\n";
//		cout<<f<<" "<<c<<"\n";
		return max(0,c-f);
	}
	int m=(l+r)>>1;
	return query(v<<1,l,m,lq,min(rq,m),a,b)+query((v<<1)+1,m+1,r,max(lq,m+1),rq,a,b);
}

int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
	vi temp;
	for(int i=0;i<=4*n+5;i++) ST.push_back(temp);
	build(1,1,n);
	int Q;scanf("%d",&Q);
	int q,a,b,c,d;
	for(int i=0;i<Q;i++){
		scanf("%d",&q);
		if(q==1){
			scanf("%d %d %d %d",&a,&b,&c,&d);
			cout<<query(1,1,n,a+1,b+1,c,d)<<"\n";
		}
		else{
			scanf("%d %d",&a,&b);
			update(1,1,n,a+1,b,arr[a+1]);
			arr[a+1]=b;
		}
	}
}