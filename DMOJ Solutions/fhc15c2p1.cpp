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

void solve(){
    int n; scan(n);
    int arr[n];
    FOR(i,0,n) scan(arr[i]);
    int bottom=arr[0]; int top=arr[0];
    int l=1; int r=n-1;
    while(l<=r){
        if(arr[l]==bottom+1){
            bottom++; l++;
        } else if(arr[l]==top-1){
            top--; l++;
        } else if(arr[r]==bottom+1){
            bottom++; r--;
        } else if(arr[r]==top-1){
            top--; r--;
        } else break;
    }
    if(l<=r){
        l=0; r=n-2; bottom=top=arr[n-1];
        while(l<=r){
            if(arr[l]==bottom+1){
                bottom++; l++;
            } else if(arr[l]==top-1){
                top--; l++;
            } else if(arr[r]==bottom+1){
                bottom++; r--;
            } else if(arr[r]==top-1){
                top--; r--;
            } else break;
        }

        if(l<=r) cout<<"no\n";
        else cout<<"yes\n";

    }
    else cout<<"yes\n";
}

int main(){
    IOS;
    int t; scan(t);
    FOR(i,1,t+1) {
        cout<<"Case #"<<i<<": "; solve();
    }
}