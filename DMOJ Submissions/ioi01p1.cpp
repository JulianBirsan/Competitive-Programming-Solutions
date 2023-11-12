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

const int mx=1025;

int bit[mx][mx],s,x,y,a,q,l,b,r,t;

void update(int I,int J,int val){
    for(int i=I;i<s;i=i|(i+1)){
        for(int j=J;j<s;j=j|(j+1)){
            bit[i][j]+=val;
        }
    }
}

int query(int I,int J){
    int ret=0;
    for(int i=I;i>=0;i=(i&(i+1))-1){
        for(int j=J;j>=0;j=(j&(j+1))-1){
            ret+=bit[i][j];
        }
    }
    return ret;
}

int main(){
    IOS;
    scan(q,s);
    scan(q);
    while(q!=3){
        if(q==1){
            scan(x,y,a);
            update(x,y,a);
        } else{
            scan(l,b,r,t);
            int ans=query(r,t)-query(l-1,t)-query(r,b-1)+query(l-1,b-1);
            cout<<ans<<"\n";
        }
        scan(q);
    }
}