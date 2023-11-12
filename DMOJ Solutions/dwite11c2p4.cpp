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
#define MAXLN numeric_limits<int>::max()
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

int outdeg[1000];
bool seen[1000];
vector<vi> graph(1000);

void solve(){
    fill(outdeg); fill(seen);
    FOR(i,0,1000) graph[i].clear();
    int n; scan(n);
    int x,y;
    FOR(i,0,n-1){
        scan(x,y);
        outdeg[x]++;
        outdeg[y]++;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
//    FOR(i,0,n){
//        for(int u: graph[i]) cout<<u<<" ";
//        cout<<"\n";
//    }
    priority_queue<pii> q;
    q.push(pii(0,0));
    int ans=0; seen[0]=true;
    while(!q.empty()){
        ans=max(ans,int(q.size()));
        int at=q.top().second; q.pop();
        for(int u: graph[at]){
            if(!seen[u]){
                seen[u]=true;
                q.push(pii(-outdeg[u],u));
            }
        }
    }
    cout<<ans<<"\n";
}

int main(){
    IOS;
    FOR(i,0,5) solve();
}