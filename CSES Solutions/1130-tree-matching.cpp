#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> inline void maxa(T& a,T b){a=max(a,b);}
template<typename T> inline void mina(T& a,T b){a=min(a,b);}

const int mxN=2e5+5;

int dp[mxN][2],n,a,b;
vector<int> graph[mxN];

//dp[i][0] - take this node
//dp[i][1] - don't take this node

void dfs(int at,int p){
    int s=0; int no=0;
    for(int &i:graph[at]){
        if(i==p)
            continue;
        dfs(i,at);
        s+=max(dp[i][0],dp[i][1]);
        maxa(no,dp[i][1]+1-dp[i][0]);
    }
    dp[at][1]=s;
    dp[at][0]=s+no;
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
    cout<<max(dp[1][0],dp[1][1])<<"\n";
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    // }
}