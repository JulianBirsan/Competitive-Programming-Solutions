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
typedef unordered_set<int> usi;
typedef multiset<int> msi;
typedef unordered_map<int,int> umii;
typedef double db;
typedef long double ldb;

int n,m,k;
int a[5001],b[5001],wt[5001];
bool zero[1001];

bool check(int biggest,int curEdge,int cnt){
    if(curEdge==m) return true;
    if(wt[curEdge]>biggest && !zero[a[curEdge]] && !zero[b[curEdge]]){
        if(cnt==k) return false;
        zero[a[curEdge]]=1;
        bool acheck=check(biggest,curEdge+1,cnt+1);
        zero[a[curEdge]]=0;
        if(acheck) return true;
        zero[b[curEdge]]=1;
        bool bcheck=check(biggest,curEdge+1,cnt+1);
        zero[b[curEdge]]=0;
        return bcheck;
    }
    return check(biggest,curEdge+1,cnt);
}

int main(){
    IOS;
    scan(n,m);
    int ans=0;
    FOR(i,0,m){
        scan(a[i],b[i],wt[i]);
        ans=max(ans,wt[i]);
    }

    FOR(i,1,min(n+1,11)){
        k=i;
        int l=-1,r=1001;
        fill(zero);
        while(l<r-1){
            int mid=(l+r)>>1;
            if(check(mid,0,0)) r=mid;
            else l=mid;
        }
        ans=min(ans,r+i*i*10);
    }
    cout<<ans<<"\n";
}