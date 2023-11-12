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

const int MAX=6e6+1;

int parent[MAX];
char level[MAX];
bool seen[MAX];

int main(){
    IOS;
    int n,q,x,y; scan(n,q);
    fill(seen); fill(parent); fill(level);
    FOR(i,2,n+1) scan(parent[i]);
    FOR(i,2,n+1) level[i]=level[parent[i]]+1;
    while(q--){
        scan(x,y);
        if(level[x]>level[y]) swap(x,y);
        int temp=x;
        while(x){
            seen[x]=true;
            x=parent[x];
        }
        while(y){
            if(seen[y]){
                cout<<y<<"\n";
                break;
            }
            y=parent[y];
        }
        while(temp){
            seen[temp]=false;
            temp=parent[temp];
        }
    }
}