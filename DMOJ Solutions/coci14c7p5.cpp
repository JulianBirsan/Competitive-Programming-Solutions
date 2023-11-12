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

const ld PREC = 0.001;
const int MAX = 300001;
int n,k,arr[MAX];
ld suff[MAX];

bool solve(ld av){
    ld curtot=0;
    FOR(i,1,n+1){
        curtot+=arr[i]-av;
        suff[i]=curtot;
    }
    for(int i=n-1;i>0;i--){
        suff[i]=max(suff[i],suff[i+1]);
    }
    ld diff=0;
    FOR(i,1,n-k+2){
        if(suff[i+k-1]>=diff) return true;
        diff-=av-arr[i];
    }
    return false;
}

int main(){
    IOS;
    scan(n,k);
    int top=0;
    FOR(i,1,n+1){
        scan(arr[i]);top=max(top,arr[i]);
    }
    ld l=1,r=top;
    while(l+PREC<r){
        ld mid=(l+r)/ld(2);
        if(solve(mid)) l=mid;
        else r=mid;
    }
    printf("%.10Lf\n", l);
}