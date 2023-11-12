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

int circ[1000];
int ans=MAXN;

bool brute(int sz,int k,int start,int h){
    int first=circ[start];
    FOR(i,start+1,h){
        if(sz*2<circ[i]-first){
            k--;
            if(k==0) return false;
            first=circ[i];
        }
    }
    FOR(i,0,start){
        if(circ[i]<first){
            if(sz*2<circ[i]+1000000-first){
                k--;
                if(k==0) return false;
                first=circ[i];
            }
        } else{
            if(sz*2<circ[i]-first){
                k--;
                if(k==0) return false;
                first=circ[i];
            }
        }
    }
    return true;
}

bool solve(int sz,int k,int h){
    FOR(i,0,h){
        if(brute(sz,k,i,h)) return true;
    }
    return false;
}

int main(){
    IOS;
    int h; scan(h);
    FOR(i,0,h) {
        scan(circ[i]);
    }
    sort(circ,circ+h);
    int k; scan(k);
    int l=0;int r=1000000;
    while(l<=r){
        int mid=(l+r)>>1;
        if(solve(mid,k,h)){
            r=mid-1;
            ans=min(ans,mid);
        } else l=mid+1;
    }
    cout<<ans<<"\n";
}