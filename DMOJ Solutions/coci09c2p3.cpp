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

bool dp[129600];
int m[10];

void angles(int n){
    FOR(i,0,n){
        int cur=m[i];
        FOR(j,1,360*360){
            if(j-cur>=0){
                if(dp[j-cur]) dp[j]=true;
            }
            if(j+cur<129600){
                if(dp[j+cur]) dp[j]=true;
            }
        }
    }
}

int main(){
    IOS; fill(dp);
    dp[0]=true;
    int n,k; scan(n,k);
    FOR(i,0,n) scan(m[i]);
    angles(n); angles(n);
    int x;
    FOR(i,0,k){
        scan(x);
        int check=true;
        for(int j=x;j<129600;j+=360){
            if(dp[j]) {
                cout<<"YES\n"; check=false; break;
            }
        }
        if(check) cout<<"NO\n";

    }

}