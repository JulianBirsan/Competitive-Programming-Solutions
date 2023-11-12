#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=4e4+5;

int n,x,y;

bool seen[mxN];

map<int,set<int> > graph;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    set<int> ety;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        x+=20000;
        y+=20000;
        if(!seen[x]){
            seen[x]=true;
            graph[x]=ety;
        }
        graph[x].insert(y);
    }
    ll ans=0;
    for(auto i:graph){
        for(auto j:graph){
            if(i.first==j.first) continue;
            set<int> both;
            for(int u:i.second) if(j.second.count(u)) both.insert(u);
            if(both.size()<2) continue;
            ll y1=*both.begin(),y2=*both.rbegin();
            ans=max(ans,(y2-y1)*(abs(j.first-i.first)));
        }
    }
    cout<<ans<<"\n";
}