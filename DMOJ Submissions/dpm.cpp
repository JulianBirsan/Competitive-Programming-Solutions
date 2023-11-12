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

const int MAX=1e5+1;
const int M=1e9+7;

int dp[105][MAX+5];

int n,k,a;

int main(){
    IOS;
    scan(n,k);
    fill(dp);
    dp[0][0]=1;
    FOR(i,1,n+1){
        scan(a);
        int psa[k+1];
        fill(psa);
        psa[0]=dp[i-1][0];
        FOR(j,1,k+1){
            psa[j]=(psa[j-1]+dp[i-1][j])%M;
        }
        FOR(j,0,k+1){
            if(j-a-1<0) dp[i][j]=psa[j];
            else dp[i][j]=(psa[j]-psa[j-a-1]+M)%M;
        }
    }
//    FOR(i,0,n+1){
//        FOR(j,0,k+2){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
    cout<<dp[n][k]<<"\n";
}