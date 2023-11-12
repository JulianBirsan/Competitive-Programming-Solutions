#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cerr<<vars<<" = ";
    string delim="";
    (...,(cerr<<delim<<values,delim=", "));
    cerr<<"\n";
}
#else
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {}
#endif

#define pb push_back
#define sz(x) (int)(x.size())
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> inline void maxa(T& a,T b){a=max(a,b);}
template<typename T> inline void mina(T& a,T b){a=min(a,b);} 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mxN=2e5+5; //make sure this is right
const int mod=1e9+7;

int st[mxN<<4],a[mxN],cnt[mxN];

vector<int> all;
int get(int x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;}
int get2(int x){return --lower_bound(all.begin(),all.end(),x+1)-all.begin()+1;}

void update(int v,int l,int r,int ind,int val){
    if(l>ind || r<ind)
        return;
    if(l==r){
        st[v]+=val;
    } else{
        int m=(l+r)>>1;
        update(v<<1,l,m,ind,val);
        update(v<<1|1,m+1,r,ind,val);
        st[v]=st[v<<1]+st[v<<1|1];
    }
}

int query(int v,int l,int r,int lq,int rq){
    if(lq>rq)
        return 0;
    if(l>=lq && r<=rq)
        return st[v];
    int m=(l+r)>>1;
    return query(v<<1,l,m,lq,min(m,rq))+query(v<<1|1,m+1,r,max(lq,m+1),rq);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]; all.pb(a[i]);
    }
    vector<vector<int>> off;
    while(q--){
        char c; int a,b;
        cin>>c>>a>>b;
        int C=(c=='?');
        off.pb({a,b,C});
        if(c=='!')
            all.pb(b);
    }
    sort(all.begin(),all.end());
    all.resize(unique(all.begin(),all.end())-all.begin());
    for(int i=1;i<=n;i++){
        a[i]=get(a[i]);
        update(1,1,sz(all),a[i],1);
    }
    for(auto &u:off){
        if(u[2]){
            int l=get(u[0]);
            int r=get2(u[1]);
            cout<<query(1,1,sz(all),l,r)<<"\n";
        } else{
            update(1,1,sz(all),a[u[0]],-1);
            u[1]=get(u[1]);
            a[u[0]]=u[1];
            update(1,1,sz(all),a[u[0]],1);
        }
    }
}
