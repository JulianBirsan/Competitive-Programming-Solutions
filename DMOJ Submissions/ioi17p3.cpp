#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=5e3+5;

vector<int> graph[mxN],rev[mxN];

int n,m;
bool seen[mxN];

// void dfs(int at){
    // seen[at]=true;
    // if(ch[at]){
        // win[at]=1;
        // return;
    // }
    // for(int &i:graph[at]){
        // if(!seen[i]) dfs(i);
        // if(win[i]==own[at]){
            // win[at]=own[at];
            // return;
        // }
    // }
    // win[at]=!own[at];
// }

vector<int> f(vector<int> &own,vector<int> &arr,int t){
    vector<int> ret,deg(n);
    for(int i=0;i<n;i++){
        if(seen[i]) continue;
        for(int &j:rev[i]) deg[j]+=(!seen[j]);
    }
    queue<int> q;
    for(int &i:arr){
        deg[i]=0;
        q.push(i);
    }
    while(!q.empty()){
        int at=q.front();
        q.pop();
        ret.push_back(at);
        for(int &i:rev[at]){
            if(seen[i]) continue;
            if(own[i]==t && deg[i]>0){
                deg[i]=0;
                q.push(i);
            } else if(own[i]!=t){
                deg[i]--;
                if(deg[i]==0) q.push(i);
            }
        }
    }
    return ret;
}

vector<int> who_wins(vector<int> a, vector<int> r, vector<int> u, vector<int> v){
    n=a.size();
    m=u.size();
    vector<int> win(n);
    for(int i=0;i<m;i++){
        rev[v[i]].push_back(u[i]);
    }
    while(true){
        int cnt=count(seen,seen+n,0);
        vector<int> arr;
        for(int i=0;i<n;i++){
            if(!seen[i] && r[i]){
                arr.push_back(i);
            }
        }
        if(cnt==0) break;
        arr=f(a,arr,1);
        if(arr.size()==cnt){
            for(int &i:arr) seen[i]=true,win[i]=1;
        } else{
            vector<int> temp(n);
            for(int &i:arr) temp[i]=1;
            arr.clear();
            for(int i=0;i<n;i++){
                if(!seen[i] && !temp[i]) arr.push_back(i);
            }
            arr=f(a,arr,0);
            for(int &i:arr) seen[i]=true;
        }
    }
    return win;
}