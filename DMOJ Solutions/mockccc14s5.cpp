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

const int MAX=100;
int w[MAX],b[MAX];
int oc[MAX];
bool seen[MAX];

vector<vi> graph(MAX);

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

bool match(int at){
    if(at==-1) return false;
    for(int i: graph[at]){
        if(!seen[i]){
            seen[i]=true;
            if(oc[i]==-1||match(oc[i])){
                oc[i]=at;
                return true;
            }
        }
    }
    return false;
}

int main(){
    IOS; fill(w); fill(b);FOR(i,0,MAX) oc[i]=-1;
    int n,m; scan(n,m);
    FOR(i,0,n) scan(w[i]);
    FOR(i,0,m){
        scan(b[i]);
        FOR(j,0,n){
            if(gcd(b[i],w[j])>1) graph[i].push_back(j);
        }
    }
    int out=0;
    FOR(i,0,m){
        fill(seen);
        out+=match(i);
    }
    cout<<out*2<<"\n";
}