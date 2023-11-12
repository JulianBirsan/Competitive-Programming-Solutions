#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define read(v,n) for(int i=0;i<n;i++) scan(v[i])
#define fill(x) memset(x,0,sizeof(x))
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<long long int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;
typedef pair<string,double> psd;
typedef unordered_set<int> usi;
typedef multiset<int> msi;
typedef unordered_map<int,int> umii;
typedef double db;
typedef long double ld;

const int mx=1e5+1;

bitset<1001> st[4*mx];
int arr[mx],cnt=0;
queue<int> ety;
umii freq,ind;

int n,q,t,u,v;

void update(int v,int l,int r,int idx,int val){
    if(l>idx||r<idx) return;
    if(l==r){
        st[v].reset();
        st[v][val]=1;
    } else{
        int m=(l+r)>>1;
        update(v<<1,l,m,idx,val);
        update(v<<1|1,m+1,r,idx,val);
        st[v]=st[v<<1]|st[v<<1|1];
    }
}

bitset<1001> query(int v,int l,int r,int lq,int rq){
    bitset<1001> ret;
    if(lq>rq) return ret;
    if(l>=lq&&r<=rq) return st[v];
    int m=(l+r)>>1;
    return query(v<<1,l,m,lq,min(rq,m))|query(v<<1|1,m+1,r,max(lq,m+1),rq);
}

int main(){
    IOS;
    scan(n,q);
    FOR(i,1,n+1){
        scan(arr[i]);
        freq[arr[i]]++;
        if(ind[arr[i]]==0){
            ind[arr[i]]=++cnt;
        }
        update(1,1,n,i,ind[arr[i]]);
    }
    while(q--){
        scan(t,u,v);
        if(t==1){
            freq[arr[u]]--;
            if(freq[arr[u]]==0){
                ety.push(ind[arr[u]]);
                ind[arr[u]]=0;
            }
            freq[v]++;
            if(freq[v]==1){
                if(!ety.empty()){
                    ind[v]=ety.front();
                    ety.pop();
                } else ind[v]=++cnt;
            }
            update(1,1,n,u,ind[v]);
        } else{
            bitset<1001> ans=query(1,1,n,u,v);
            cout<<ans.count()<<"\n";
        }
    }
}