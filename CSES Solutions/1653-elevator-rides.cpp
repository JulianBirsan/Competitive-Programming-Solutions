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

const int mxN=5e5+5,mxS=710; //make sure this is right
const int mod=1e9+7;

pii dp[1<<20];
int n,x;
ll sum[1<<20],w[20];

pii make(int mask){
    if(~dp[mask].first)
        return dp[mask];
    if(sum[mask]<x)
        return dp[mask]={0,sum[mask]};
    if(sum[mask]==x)
        return dp[mask]={1,0};
    pii res={1e9,1e9};
    for(int i=0;i<n;i++){
        if(mask&(1<<i)){
            pii lhs=make(1<<i);
            pii rhs=make(mask^(1<<i));
            pii cur;
            if(lhs.second+rhs.second<x)
                cur={lhs.first+rhs.first,lhs.second+rhs.second};
            else if(lhs.second+rhs.second==x)
                cur={lhs.first+rhs.first+1,0};
            else
                cur={lhs.first+rhs.first+1,min(lhs.second,rhs.second)};
            mina(res,cur);
        }
    }
    return dp[mask]=res;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>w[i];
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j))
                sum[i]+=w[j];
        }
        dp[i]={-1,-1};
    }
    pii res=make((1<<n)-1);
    int ans=res.first+(res.second?1:0);
    cout<<ans<<"\n";
}
