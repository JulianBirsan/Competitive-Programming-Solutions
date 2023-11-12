#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxN=4e5+1;

bool bad[mxN];
vector<int> graph[mxN];
vector<int> ans,rem;

int n,m,k,uf[mxN],num,u,v;

int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);}
bool same(int x,int y){return find(x)==find(y);}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(uf[x]>uf[y]) swap(x,y);
    uf[x]+=uf[y];
    uf[y]=x;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(uf,-1,sizeof(uf));
    cin>>n>>m;
    num=n;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>u;
        rem.push_back(u);
        bad[u]=true;
    }
    num-=k;
    for(int i=0;i<n;i++){
        if(!bad[i]){
            for(int &j:graph[i]){
                if(!bad[j] && !same(i,j)){
                    unite(i,j);
                    num--;
                }
            }
        }
    }
    ans.push_back(num);
    for(int i=k-1;i>=0;i--){
        int k=rem[i];
        bad[k]=false;
        num++;
        for(int &j:graph[k]){
            if(!bad[j] && !same(k,j)){
                num--;
                unite(k,j);
            }
        }
        ans.push_back(num);
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<"\n";
    }
}