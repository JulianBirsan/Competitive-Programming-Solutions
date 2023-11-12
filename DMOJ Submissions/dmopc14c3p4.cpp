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

const int mxN=1e5+1;

int psa[mxN][129],k,a,b,t;

int fact(int x){
    int ret=0;
    FOR(i,1,(int)sqrt(x)+1) {
        if(x%i==0){
            ret++;
            ret+=x/i>sqrt(x);
        }
    }
    return ret;
}

int main(){
    IOS;
    FOR(i,1,100001) {
        int f=fact(i);
        if(i==1) f=1;
        else if(i<=3) f=2;
        psa[i][f]++;
        FOR(j,1,129) psa[i][j]+=psa[i-1][j];
    }
    scan(t);
    while(t--){
        scan(k,a,b);
        if(k>128) cout<<0<<"\n";
        else cout<<psa[b][k]-psa[a-1][k]<<"\n";
    }
}