#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=5e3+5,inf=1e9;

int dist[mxN][mxN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    int n,q,x,y;
    for(int i=0;i<mxN;i++){
        for(int j=0;j<mxN;j++){
            dist[i][j]=inf;
        }
    }

    queue<pii> qu;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        qu.push(pii(x,y));
        dist[x][y]=0;
    }
    while(!qu.empty()){
        x=qu.front().first;
        y=qu.front().second;
        qu.pop();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0 && j==0)
                    continue;
                int xx=x+i;
                int yy=y+j;
                if(xx>5000 || yy>5000 || yy<0 || xx<0){
                    continue;
                }
                if(dist[xx][yy]>dist[x][y]+1){
                    dist[xx][yy]=dist[x][y]+1;
                    qu.push(pii(xx,yy));
                }
            }
        }
    }
    while(q--){
        cin>>x>>y;
        cout<<dist[x][y]<<"\n";
    }
}