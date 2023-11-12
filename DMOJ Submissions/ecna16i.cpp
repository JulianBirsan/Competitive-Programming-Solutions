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
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<long long int>::max()
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef double db;
typedef long double ld;

vector<int> graph[101],group[101];

int oc[101],n,m,p,cat[101],sz[101][2],ans,k,l,r,t; 
bool seen[101];

bool match(int at){
    if(at==-1) return false;
    for(int i:graph[at]){
        if(seen[i]) continue;

        seen[i]=true;

        if(oc[i]==-1 || match(oc[i])){

            if(cat[i]==-1){
                oc[i]=at;
                return true;
            }

            if(oc[i]!=-1){
                sz[cat[i]][1]--;
                oc[i]=-1;
            }

            if(sz[cat[i]][1]<sz[cat[i]][0]){
                sz[cat[i]][1]++;
                oc[i]=at;
                return true;
            }

            for(int j:group[cat[i]]){
                if(!seen[j]){
                    if(match(oc[j])) {
                        oc[i]=at;
                        return true;
                    }
                }
            }
        }
        
    }
    return false;
}

int main(){
    IOS;

    memset(oc,-1,sizeof(oc));
    memset(cat,-1,sizeof(cat));

    scan(n,m,p);

    FOR(i,0,n){
        scan(k);
        while(k--){
            scan(t);
            graph[i].push_back(t);
        }
    }

    FOR(i,0,p){
        scan(l);
        while(l--){
            scan(t);
            cat[t]=i;
            group[i].push_back(t);
        }
        scan(r);
        sz[i][0]=r;
    }

    FOR(i,0,n) {
        ans+=match(i);
        memset(seen,0,sizeof(seen));
    }

    cout<<ans<<"\n";
}