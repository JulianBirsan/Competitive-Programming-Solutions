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

const int mx=1005;

ll pda[mx];
int t,l,n,c,r,d,m,h;

void solve(){
    scan(l,n);
    fill(pda);
    FOR(i,0,n){
        scan(c,r,d);
        pda[max(1,c-r)]+=d;
        pda[min(l+2,c+r+1)]-=d;
    }
    FOR(i,1,l+1){
        pda[i]+=pda[i-1];
    }
    scan(m);
    FOR(i,0,m){
        scan(h);
        FOR(j,1,l+1){
            h-=pda[j];
            if(h<=0) {
                cout<<j<<"\n";
                break;
            }
        }
        if(h>0) cout<<"Bloon leakage\n";
    }
}

int main(){
    IOS;
    scan(t);
    while(t--) solve();
}