#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F f,R... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)
#define OUT_OPERATOR(type, propa, propb) ostream& operator<<(ostream& out,type obj){out<<"("<<#propa<<"="<<obj. propa<<", "<<#propb<<"="<<obj. propb<<")";return out;}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define fill(x) memset(x,0,sizeof(x))
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<long long int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;
typedef pair<string,double> psd;
typedef double d;
typedef long double ld;

vector<vi> graph(5001);
int parent[5001];
bool seen[5001],seen2[5001];
vector<pii> order;

void dfs(int at,int height){
    order[at].first=height++;
    FOR(i,0,graph[at].size()){
        int &to=graph[at][i];
        if(to!=parent[at]){
            parent[to]=at;
            dfs(to,height);
        }
    }
}

int centroid(int at,int sz){
    return sz==0 ? at:centroid(parent[at],sz-1);
}

void solve(int at,int sz){
    if(sz==-1) return;
    seen[at]=seen2[at]=true;
    for(int i:graph[at]) if(!seen[i]){
        solve(i,sz-1);
    }
}

int inter(int sz,int n){
    fill(seen2);
    int cnt,cent;
    cnt=cent=0;
    FOR(i,0,n){
        int cur=order[i].second;
        if(!seen2[cur]){
            fill(seen);
            cent=centroid(cur,sz);
            solve(cent,sz);
            cnt++;
        }
    }
    return cnt;
}

int main(){
    IOS;
    int n,s,u,v; scan(n,s);
    order.resize(n);
    FOR(i,0,n) order[i]=(pii(0,i));
    FOR(i,0,n-1){
        scan(u,v);
        graph[--u].push_back(--v);
        graph[v].push_back(u);
    }
    dfs(0,-1);
    sort(order.rbegin(),order.rend());
    int l=0; int r=5000;
    while(l<=r){
        int mid=(l+r)/2;
        if(s>=inter(mid,n)){
            r=mid-1;
        } else l=mid+1;
    }
    cout<<l<<"\n";
}