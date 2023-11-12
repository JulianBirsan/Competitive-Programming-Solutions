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

d total=0;
vi arr;

d merge(int l,int m,int r){
    d ret=0;
    vi newArr; newArr.resize(r-l+1);
    int lc=l; int mc=m+1; int ind=0;
    while(lc<=m&&mc<=r){
        if(arr[lc]<=arr[mc]){
            newArr[ind++]=arr[lc++];
        } else{
            newArr[ind++]=arr[mc++];
            ret+=m+1-lc;
        }
    }
    while(lc<=m) newArr[ind++]=arr[lc++];
    while(mc<=r) newArr[ind++]=arr[mc++];
    for(int lc=l;lc<=r;lc++){
        arr[lc]=newArr[lc-l];
    }
    return ret;
}

void mergeSort(int l,int r){
    if(l<r){
        int m=(l+r)>>1;
        mergeSort(l,m);
        mergeSort(m+1,r);
        total+=merge(l,m,r);
    }
}

int main(){
    IOS; int n; scan(n);
    arr.resize(n);
    FOR(i,0,n) scan(arr[i]);
    mergeSort(0,n-1);
    cout<<fixed<<setprecision(2)<<(total+n)/n<<"\n";
}