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

const int mx=1e6+1;

int arr[mx],bit[mx],n,q,l,r;
int output[mx];

void update(int x,int val){
    x++;
    while(x<mx){
        bit[x]+=val;
        x+=x&(-x);
    }
}

int query(int x){
    int ret=0;
    while(x>0){
        ret+=bit[x];
        x-=x&(-x);
    }
    return ret;
}

deque<int> stk;

vector<vector<int> > queries;

int main(){
    IOS;
    scan(n,q);
    FOR(i,1,n+1) scan(arr[i]);
    FOR(i,0,q){
        scan(l,r);
        vi temp;
        temp.push_back(l); temp.push_back(r); temp.push_back(i);
        queries.push_back(temp);
    }
    sort(queries.rbegin(),queries.rend());
    int ind=0;
    for(int i=n;i>=1;i--){
        if(ind==q) break;
        while(!stk.empty()&&arr[i]>arr[stk.back()]){
            update(stk.back(),-1);
            stk.pop_back();
        }
        stk.push_back(i);
        update(i,1);
        while(queries[ind][0]==i){
            output[queries[ind][2]]=query(queries[ind][1]+1);
            ind++;
            if(ind==q) break;
        }
    }
    FOR(i,0,q) cout<<output[i]<<"\n";
}