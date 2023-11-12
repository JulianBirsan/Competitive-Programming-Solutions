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

struct qu{
    int l,r,i;
    bool operator<(const qu &o) const{
        return r<o.r;
    }
};

vector<int> all;
int get(int x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;}

struct BIT{
    ll bit[mxN]; 
    void upd(int x,int v){while(x<mxN){bit[x]+=v;x+=x&-x;}}
    ll sum(int x){ll res=0;while(x){res+=bit[x];x-=x&-x;}return res;} 
};

BIT bit;    
int lst[mxN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,q; cin>>n>>q;
    vector<int> a(n+1),ans(q);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        all.pb(a[i]);
    }
    sort(all.begin(),all.end());
    all.resize(unique(all.begin(),all.end())-all.begin());
    for(int &i:a)
        i=get(i);
    vector<qu> off;
    for(int i=0;i<q;i++){
        int l,r; cin>>l>>r;
        off.pb({l,r,i});
    }
    memset(lst,-1,sizeof(lst));
    sort(off.begin(),off.end());
    int j=1;
    for(auto &u:off){
        while(j<=u.r){
            if(~lst[a[j]])
                bit.upd(lst[a[j]],-1);
            lst[a[j]]=j;
            bit.upd(j,1);
            j++;
        }
        ans[u.i]=bit.sum(u.r)-bit.sum(u.l-1);
    }
    for(int i=0;i<q;i++)
        cout<<ans[i]<<"\n";
}
