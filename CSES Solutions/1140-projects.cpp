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

const int mxN=4e5+5;

ll dp[mxN];
vector<int> all;
vector<pii> at[mxN];
int get(int x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;};
 
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
 
    int n; cin>>n;
    vector<vector<int>> tmp;
    for(int i=0;i<n;i++){
        int a,b,p; cin>>a>>b>>p;
        tmp.pb({a,b,p});
        all.pb(a); all.pb(b);
    }
    sort(all.begin(),all.end());
    all.resize(unique(all.begin(),all.end())-all.begin());
    for(auto i:tmp){
        at[get(i[1])].pb({get(i[0]),i[2]});
    }
    for(int i=1;i<=2*n;i++){
        for(auto u:at[i])
            maxa(dp[i],u.second+dp[u.first-1]);
        maxa(dp[i],dp[i-1]);
    }
    cout<<dp[2*n]<<"\n";
}
