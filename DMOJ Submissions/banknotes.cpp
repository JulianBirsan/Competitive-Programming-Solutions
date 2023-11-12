#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define read(v,n) for(int i=0;i<n;i++) scan(v[i])
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
typedef double db;
typedef long double ld;

const int MAX=2e4+1;

int b[200],c[200];
int seen[MAX];

vi dp;

int n,k;

int main(){
    IOS;
    scan(n);
    read(b,n);
    read(c,n);
    scan(k);
    dp.assign(k+1,-1);
    dp[0]=0;
    memset(seen,-1,sizeof(seen));
    FOR(i,0,n){
        vi cur=dp;
        FOR(j,b[i],k+1){
            if(dp[j-b[i]]!=-1 && seen[j]!=i){
                seen[j]=i;
                cur[j]=cur[j]==-1 ? dp[j-b[i]]+1:min(cur[j],dp[j-b[i]]+1);
                FOR(p,1,c[i]){
                    if(j+b[i]*p<=k){
                        if(seen[j+b[i]*p]==i) break;
                        seen[j+b[i]*p]=i;
                        int bef=cur[j+b[i]*p];
                        cur[j+b[i]*p]=cur[j+b[i]*p]==-1 ? cur[j+b[i]*(p-1)]+1:min(cur[j+b[i]*p],cur[j+b[i]*(p-1)]+1);
                        if(cur[j+b[i]*p]==bef) break;
                    } else break;
                }
            }
        }
        dp=cur;
    }
    cout<<dp[k]<<"\n";
}