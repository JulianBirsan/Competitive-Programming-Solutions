#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=2e5+1;

vector<int> graph[mxN];

int n,a,b,mt[mxN];
vector<pii> ans;

void dfs(int at,int prev){
    queue<int> q;
    for(int &i:graph[at]){
        if(i!=prev) {
            dfs(i,at);
            if(!mt[i]) q.push(i);   
        }
    }
    while(q.size()>1){
        int tp=q.front();
        q.pop();
        int sc=q.front();
        q.pop();
        ans.push_back(pii(tp,sc));
    }
    if(q.size() && prev!=-1){
        int tp=q.front();
        mt[at]=true;
        ans.push_back(pii(prev,tp));
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,-1);
    cout<<ans.size()<<"\n";
    for(pii &i:ans){
        cout<<i.first<<" "<<i.second<<"\n";
    }
}