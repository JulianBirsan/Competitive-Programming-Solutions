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
#define sz(x) (ll)(x.size())
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> inline void maxa(T& a,T b){a=max(a,b);}
template<typename T> inline void mina(T& a,T b){a=min(a,b);} 

const int mxN=8e5+5;

int bit[mxN],ans[mxN],ans2[mxN];

void upd(int x,int v){while(x<mxN){bit[x]+=v;x+=x&-x;}}
ll sum(int x){ll res=0;while(x){res+=bit[x];x-=x&-x;}return res;}

struct interval{
    int l,r,i;
};

vector<int> all;
int get(int x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n; cin>>n;
    vector<interval> rng;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        all.pb(x); all.pb(y);
        rng.pb({x,y,i});
    }
    sort(rng.begin(),rng.end(),[&](auto a,auto b){return a.l==b.l?a.r>b.r:a.l<b.l;});
    sort(all.begin(),all.end());
    all.resize(unique(all.begin(),all.end())-all.begin());
    for(auto &i:rng){
        i.l=get(i.l);
        i.r=get(i.r);
    }
    for(int i=0;i<n;i++){
        ans2[rng[i].i]=sum(4*n)-sum(rng[i].r-1);
        upd(rng[i].r,1);
    }
    memset(bit,0,sizeof(bit));
    sort(rng.begin(),rng.end(),[&](auto a,auto b){return a.l==b.l?a.r<b.r:a.l>b.l;});
    for(int i=0;i<n;i++){
        ans[rng[i].i]=sum(rng[i].r);
        upd(rng[i].r,1);
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" \n"[i==n-1];
    for(int i=0;i<n;i++)
        cout<<ans2[i]<<" \n"[i==n-1];
}
