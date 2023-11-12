#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x.size())
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> inline void maxa(T& a,T b){a=max(a,b);}
template<typename T> inline void mina(T& a,T b){a=min(a,b);}

const int mxN=2e5+5;

int dp[mxN][2],n,a,b;
vector<int> graph[mxN];

void dfs(int at,int p){
    for(int &i:graph[at]){
        if(i==p)
            continue;
        dfs(i,at);
        maxa(dp[at][1],dp[i][0]+1);
        if(dp[at][1]>dp[at][0])
            swap(dp[at][0],dp[at][1]);
    }
}

void par(int at,int p){
    if(p!=-1){
        if(dp[p][0]==dp[at][0]+1)
            maxa(dp[at][1],dp[p][1]+1);
        else
            maxa(dp[at][1],dp[p][0]+1);
        if(dp[at][0]<dp[at][1])
            swap(dp[at][0],dp[at][1]);
    }
    for(int &i:graph[at]){
        if(i==p)
            continue;
        par(i,at);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,-1);
    par(1,-1);
    for(int i=1;i<=n;i++)
        cout<<dp[i][0]<<" ";
}