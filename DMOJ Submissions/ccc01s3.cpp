#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<int> graph[26];

int seen[26],low[26],id[26],curid,ans;

void dfs(int at,int prev){
    seen[at]=true;
    id[at]=low[at]=++curid;
    for(int &i:graph[at]){
        if(!seen[i]) dfs(i,at);
        if(i!=prev){
            low[at]=min(low[i],low[at]);
        }
    }
    if(low[at]>id[prev] && prev!=-1){
        ans++;
        // cout<<low[at]<<" "<<id[prev]<<"\n";
        cout<<char(at+'A')<<char(prev+'A')<<"\n";
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin>>s;
    while(s!="**"){
        int u=s[0]-'A';
        int v=s[1]-'A';
        graph[u].push_back(v);
        graph[v].push_back(u);
        cin>>s;
    }
    for(int i=0;i<26;i++){
        if(!seen[i]) dfs(i,-1);
    }
    cout<<"There are "<<ans<<" disconnecting roads.\n";
}