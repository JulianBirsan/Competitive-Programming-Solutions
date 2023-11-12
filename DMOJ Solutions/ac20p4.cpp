#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=3e3+1;

vector<int> graph[mxN];
vector<pii> prs;

bool good[mxN][mxN];

int n,m,a,b;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(a>b) swap(a,b);
        graph[a].push_back(b);
        graph[b].push_back(a);
        good[a][b]=good[b][a]=true;
        prs.push_back(pii(a,b));
    }
    for(int i=1;i<=n;i++) sort(graph[i].begin(),graph[i].end());
    for(int i=1;i<=n;i++){
        for(int &j:graph[i]){
            for(int &k:graph[j]){
                if(good[i][k]){
                    cout<<3<<"\n";
                    cout<<i<<" "<<min(j,k)<<" "<<max(j,k)<<"\n";
                    return 0;
                }
            }
        }
    }
    sort(prs.begin(),prs.end());
    for(int i=0;i<m;i++){
        a=prs[i].first,b=prs[i].second;
        for(int j=i+1;j<m;j++){
            if(prs[j].first!=a && prs[j].first!=b && prs[j].second != a && prs[j].second !=b){
                int out[4]={a,b,prs[j].first,prs[j].second};
                sort(out,out+4);
                cout<<4<<"\n";
                cout<<out[0]<<" "<<out[1]<<" "<<out[2]<<" "<<out[3]<<"\n";
                return 0;
            }
        }
    }
    cout<<-1<<"\n";
}