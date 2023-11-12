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


int main(){
    vi left,right;
    int ans=MAXN;
    IOS; left.push_back(0); right.push_back(0);
    int n,t,x; scan(n,t);
    FOR(i,0,n){
        scan(x);
        if(x>0) right.push_back(x);
        else left.push_back(abs(x));
    }
    sort(rng(right));
    sort(rng(left));
    int l=left.size(); int r=right.size();
    FOR(i,0,r){
        if(t-i+1<=l&&t-i>=0){
            ans=min(2*min(right[i],left[t-i])+max(right[i],left[t-i]),ans);
        }
    }
    FOR(i,0,l){
        if(t-i+1<=r&&t-i>=0){
            ans=min(2*min(right[t-i],left[i])+max(right[t-i],left[i]),ans);
        }
    }
    cout<<ans<<"\n";
}