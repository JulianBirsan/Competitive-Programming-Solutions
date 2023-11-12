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

const int mxN=1e5+5; //make sure this is right
const int mod=1e9+7;

struct DSU{
    int uf[mxN];
    void init(){memset(uf,-1,sizeof(uf));}
    int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);}
    bool same(int x,int y){return find(x)==find(y);}
    void unite(int x,int y){
        x=find(x); y=find(y);
        if(x==y)
            return;
        if(uf[x]>uf[y])
            swap(x,y);
        uf[x]+=uf[y]; uf[y]=x;
    }   
};

DSU dsu;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    dsu.init();
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        dsu.unite(a,b);
    }
    vector<int> ans;
    for(int i=2;i<=n;i++){
        if(!dsu.same(1,i)){
            dsu.unite(1,i);
            ans.pb(i);
        }
    }
    cout<<sz(ans)<<"\n";
    for(auto &u:ans){
        cout<<"1 "<<u<<"\n";
    }
}
