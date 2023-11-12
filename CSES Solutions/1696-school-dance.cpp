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

const int mxN=500+5; //make sure this is right
const int mod=1e9+7;

int oc[mxN],seen[mxN];
vector<int> graph[mxN];

bool match(int at){
    for(int &i:graph[at]){
        if(seen[i]) continue;
        seen[i]=1;
        if(oc[i]==-1 || match(oc[i])){
            oc[i]=at;
            return 1;
        }
    }
    return 0;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,m,k; cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
    }
    memset(oc,-1,sizeof(oc));
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(seen,0,sizeof(seen));
        ans+=match(i);
    }
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++){
        if(~oc[i]){
            cout<<oc[i]<<" "<<i<<"\n";
        }
    }
}
