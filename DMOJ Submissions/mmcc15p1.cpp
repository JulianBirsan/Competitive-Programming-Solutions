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

template<int MAX>
struct UF{
    int parent[MAX]; vector<vi> history;

    void init(int n){
        FOR(i,0,n+1) parent[i]=-1;
    }
    int find(int x){
        return parent[x]<0 ? x:find(parent[x]);
    }
    void unite(int x,int y){
        if((x=find(x))==(y=find(y))) {
            vi temp; temp.push_back(x); temp.push_back(y); temp.push_back(0);
            history.push_back(temp);
            return;
        }
        if(x>y) swap(x,y);
        vi temp; temp.push_back(x); temp.push_back(y); temp.push_back(parent[y]);
        history.push_back(temp);
        parent[x]+=parent[y];
        parent[y]=x;
    }
    void undo(){
        vi edge=history.back(); history.pop_back();
        if(edge[2]==0) return;
        parent[edge[1]]=edge[2];
        parent[edge[0]]-=edge[2];
    }
    int getSize(int x){
        return -parent[find(x)];
    }
};

const int MAX=500001;
UF<MAX> uf;

void Init(int N){
    uf.init(N);
}

void AddEdge(int U, int V){
    uf.unite(U,V);
}

void RemoveLastEdge(){
    uf.undo();
}

int GetSize(int U){
    return uf.getSize(U);
}