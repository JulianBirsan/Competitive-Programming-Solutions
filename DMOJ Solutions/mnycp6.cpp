#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;


int ST[40005];

void update(int R,int v,int l,int r,int ind){
	if(r<ind||l>ind)return;
	if(l==r){
		//cout<<l<<" "<<r<<" "<<R<<"\n";
		ST[v]=R;
		return;
	}
	//cout<<l<<" "<<r<<"\n";
	int m=(l+r)>>1;
	update(R,v<<1,l,m,ind);
	update(R,(v<<1)+1,m+1,r,ind);
	//cout<<"ok\n";
	//cout<<ST[v<<1]<<" "<<ST[(v<<1)+1]<<"\n";
	ST[v]=ST[v<<1]+ST[(v<<1)+1];
}

int sum(int v,int l,int r,int lq,int rq){
	if(lq>rq)return 0;
	if(l>=lq&&r<=rq)return ST[v];
	int m=(l+r)>>1;
	return sum(v<<1,l,m,lq,min(rq,m)) + sum((v<<1)+1,m+1,r,max(lq,m+1),rq);
}

int getval(string s){
	int ans=0;
	for(int i = 0; i < s.size();i++){
		ans+=s[i]-96;
	}
	return ans;
}

unordered_map<string,pii> rocks;
int sz=0;

int main(){
	memset(ST,0,sizeof(ST));
	cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c;cin>>c;
	char q; string x,y;
	for(int i=0;i<c;i++){
		cin>>q;
		if(q=='A'){
			cin>>x;
			if(rocks.count(x)==0){
				sz++;
				int vl = getval(x);
				//cout<<vl<<"\n";
				update(vl,1,1,10000,sz);
				rocks[x] = make_pair(sz,vl);
			}
			else cout<<"Can't add "<<x<<"\n";
		}
		else if(q=='S'){
			cin>>x>>y;
			swap(rocks[x].first,rocks[y].first);
			update(rocks[x].second,1,1,10000,rocks[x].first);
			update(rocks[y].second,1,1,10000,rocks[y].first);
		}
		else if(q=='M'){
			cin>>x>>y;
			cout<<sum(1,1,10000,min(rocks[x].first,rocks[y].first),max(rocks[y].first,rocks[x].first))<<"\n";
		}
		else if(q=='R'){
			cin>>x>>y;
			int vl=getval(y);
			update(vl,1,1,10000,rocks[x].first);
			rocks[y]=make_pair(rocks[x].first,vl);
			rocks.erase(x);
		}
		else{
			cout<<sz<<"\n";
		}
	}
}