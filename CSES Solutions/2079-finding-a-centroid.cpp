#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> inline void maxa(T& a,T b){a=max(a,b);}
template<typename T> inline void mina(T& a,T b){a=min(a,b);}

const int mxN=2e5+5;

int sub[mxN],n,a,b;
vector<int> graph[mxN];

void dfs(int at,int p){
    sub[at]=1;
    for(int &i:graph[at]){
        if(i==p)
            continue;
        dfs(i,at);
        sub[at]+=sub[i];
    }
}

int centroid(int at,int p){
    for(int &i:graph[at]){
        if(i==p)
            continue;
        if(sub[i]*2>=n)
            return centroid(i,at);
    }
    return at;
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
    cout<<centroid(1,-1)<<"\n";
}