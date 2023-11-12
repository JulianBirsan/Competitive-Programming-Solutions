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

vector<int> ask[mxN];
int uf[mxN],A[mxN],B[mxN],ans[mxN],ptr[mxN];
int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);}
bool same(int a,int b){return find(a)==find(b);}
void unite(int x,int y,int d){
    x=find(x); y=find(y);
    if(uf[x]>uf[y])
        swap(x,y);
    int p=sz(ask[ptr[x]])<sz(ask[ptr[y]])?ptr[x]:ptr[y];
    int o=p==ptr[x]?ptr[y]:ptr[x];
    uf[x]+=uf[y]; uf[y]=x;
    for(int &i:ask[p]){
        int f=find(A[i]);
        int s=find(B[i]);
        if(f==s)
            ans[i]=~ans[i]?ans[i]:d;
        else
            ask[o].pb(i);
    }
    ptr[x]=o;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,m,q; cin>>n>>m>>q;
    memset(ans,-1,sizeof(ans));
    vector<pii> add;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        add.pb({a,b});
    }
    for(int i=0;i<q;i++){
        cin>>A[i]>>B[i];
        if(A[i]==B[i])
            ans[i]=0;
        else{
            ask[A[i]].pb(i);
            ask[B[i]].pb(i);
        }
    }
    memset(uf,-1,sizeof(uf));
    for(int i=1;i<=n;i++)
        ptr[i]=i;
    for(int i=0;i<m;i++){
        int a=add[i].first;
        int b=add[i].second;
        if(same(a,b))
            continue;
        unite(a,b,i+1);
    }
    for(int i=0;i<q;i++)
        cout<<ans[i]<<"\n";
}
