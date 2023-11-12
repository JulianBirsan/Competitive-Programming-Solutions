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

const int mxN=2e5+5;

vector<int> graph[mxN];
int h[mxN];

void dfs(int at,int p){
    for(int &i:graph[at]){
        if(i==p)
            continue;
        h[i]=h[at]+1;
        dfs(i,at);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,a,b;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(1,-1);
    int mxh=0;
    for(int i=1;i<=n;i++){
        if(h[i]>h[mxh])
            mxh=i;
    }
    memset(h,0,sizeof(h));
    dfs(mxh,-1);
    int ans=0;
    for(int i=1;i<=n;i++)
        maxa(ans,h[i]);
    cout<<ans<<"\n";
}