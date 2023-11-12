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

ll dp[5001][5001];
int v[5001],p[5001];

int main(){
    IOS;
    int n; scan(n);
    int totp=0;
    FOR(i,1,n+1) {
        scan(v[i],p[i]); totp+=p[i];
    }

    FOR(i,0,5001) FOR(j,0,5001){
        if(j==0) dp[i][j]=0;
        else dp[i][j]=MAXLN;
    }
    FOR(i,1,n+1){
        int vt=v[i]/2+1;
        FOR(j,0,totp+1){
            dp[i][j]=dp[i-1][j];
            if(j>=p[i]){
                if(dp[i-1][j-p[i]]!=MAXLN) dp[i][j]=min(dp[i][j],dp[i-1][j-p[i]]+vt);
            }
        }
    }
    int pt=totp/2+1;
    ll out=MAXLN;
    FOR(i,pt,totp+1) out=min(out,dp[n][i]);
    cout<<out<<"\n";
}