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

const int MAX=1e6+1;
set<pii> pos,neg;
int freq[MAX];

int main(){
    IOS; fill(freq);
    int n,m; scan(n,m);
    FOR(i,1,n+1){
        pos.insert(pii(0,-i));
        neg.insert(pii(0,i));
    }
    int t,p;
    FOR(i,0,m){
        scan(t,p);
        if(t==1&&freq[p]!=MAXN){
            pos.erase(pos.find(pii(freq[p],-p)));
            neg.erase(neg.find(pii(-freq[p],p)));
            freq[p]=MAXN;
        }
        else if(freq[p]!=MAXN && pos.count(pii(freq[p],-p))){
            pos.erase(pos.find(pii(freq[p],-p)));
            neg.erase(neg.find(pii(-freq[p],p)));
            freq[p]++;
            pos.insert(pii(freq[p],-p));
            neg.insert(pii(-freq[p],p));
        }
        if(neg.size()==0||pos.size()==0) cout<<"Make noise\n";
        else{
            pii small=*pos.begin();
            pii big=*neg.begin();
            cout<<big.second<<" "<<abs(small.second)<<"\n";
        }
    }
}