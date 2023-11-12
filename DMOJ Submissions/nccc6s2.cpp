#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}

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

int main(){
    IOS;
    int out=0;
    int n; scan(n);
    int cnt=0;
    int cur[n];
    FOR(i,0,n) FOR(j,0,n){
        scan(cur[j]);
        if(j==0&&cnt>0){
            out=max(out,cnt);
            cnt=0;
        } else if(cur[j]!=i*n+j+1) cnt++;
        else if(cur[j]==i*n+j+1){
            out=max(out,cnt);
            cnt=0;
        }
    }
    cout<<out<<"\n";
}