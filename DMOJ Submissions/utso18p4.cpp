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

vector<vector<pii> > groups(100001);
ll ans=0;

void solve(int at){
    ll cur=0;
    sort(rng(groups[at]));
    int sz=groups[at].size();
    ll psam[sz+1],psak[sz+1]; fill(psam); fill(psak);
    FOR(i,1,sz+1){
        psam[i]=psam[i-1]+groups[at][i-1].second;
        psak[i]=psak[i-1]+groups[at][i-1].first;
    }
    FOR(i,1,sz+1){
        cur=max(cur,min(psam[i],psak[sz]-psak[i]));
    }
    ans=max(ans,cur);
}

int main(){
    IOS;
    int n; scan(n);
    int k,m;
    FOR(i,0,n){
        scan(k,m);
        groups[m+k].push_back(pii(k,m));
    }
    FOR(i,1,100001) solve(i);
    cout<<ans<<"\n";
}