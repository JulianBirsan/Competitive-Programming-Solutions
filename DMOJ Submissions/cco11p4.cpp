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

set<int> av;
umii rem;

int n,r;

int main(){
    IOS;
    scan(n);
    bool check=true;
    FOR(i,0,n){
        scan(r);
        if(i==0){
            rem[r]=2;
            av.insert(r);
        } else{
            int num=* --av.lower_bound(r);
            if(rem[num]<1) check=false;
            else{
                rem[num]--;
                if(rem[num]==0){
                    av.erase(num);
                }
            }
            av.insert(r);
            rem[r]=2;
        }
    }
    if(check) cout<<"YES\n";
    else cout<<"NO\n";
}