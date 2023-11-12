#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <map>
#include <bitset>
#include <iomanip>
#include <cstring>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cmath>    

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
typedef unsigned long long ull;
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
typedef long double ld;

const int mx=2e5+1,sq=450;

int mo[sq][mx],arr[mx];

void getDiv(int i,int x,int v){
    FOR(j,1,sqrt(x)+1){
        if(x%j==0){
            if(j>sqrt(x)) break;
            mo[i][j]+=v;
            if(j!=sqrt(x)) {
                mo[i][x/j]+=v;
            }
        }
    }
}

int n,q,op,l,r,x,u,v;

int main(){
    IOS;
    scan(n,q);
    int s=sqrt(n);
    FOR(i,1,n+1) {
        scan(arr[i]);
        getDiv(int((i-1)/s),arr[i],1);
        // cout<<int((i-1)/s)<<" ";
    }
    // cout<<"\n";
    while(q--){
        scan(op);
        if(op==1){
            scan(l,r,x);
            int ans=0;
            int lft=(l-2)/s+1;
            if(l==1) lft=0;
            int rht=r/s-1;
            FOR(i,lft,rht+1) ans+=mo[i][x];
            // cout<<lft<<" "<<rht<<"\n";
            FOR(i,l,lft*s+1){
                // cout<<i<<"\n";
                ans+=arr[i]%x==0;
            }
            FOR(i,(rht+1)*s+1,r+1){
                // cout<<i<<"\n";
                ans+=arr[i]%x==0;
            }
            cout<<ans<<"\n";
        } else{
            scan(u,v);
            getDiv(int((u-1)/s),arr[u],-1);
            arr[u]=v;
            getDiv(int((u-1)/s),v,1);
        }
    }
}