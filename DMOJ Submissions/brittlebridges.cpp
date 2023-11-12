#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxN=2e5+5;

vector<pii> graph[mxN];
vector<int> cond[mxN];

ll n,comp[mxN],v[mxN],val[mxN],cur,a,b,t;

void dfs(int at,int prev){
  val[comp[at]]+=v[at];
  for(pii &i:graph[at]){
    if(i.first==prev) continue;
    if(i.second) {
      comp[i.first]=comp[at];
      dfs(i.first,at);
    } else{
      comp[i.first]=++cur;
      dfs(i.first,at);
    }
  }
}

ll solve(int at,int prev){
  ll ret=0;
  for(int &i:cond[at]){
    if(i==prev) continue;
    ret=max(ret,solve(i,at));
  }
  return ret+val[at];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin>>n;
  for(int i=1;i<=n;i++) cin>>v[i];
  for(int i=0;i<n-1;i++){
    cin>>a>>b>>t; t--;
    graph[a].push_back(pii(b,t));
    graph[b].push_back(pii(a,t));
  }
  dfs(1,-1);
  for(int i=1;i<=n;i++){
    for(pii &j:graph[i]){
      if(comp[j.first]!=comp[i]) cond[comp[i]].push_back(comp[j.first]);
    }
  }
  cout<<solve(0,-1)<<"\n";
}