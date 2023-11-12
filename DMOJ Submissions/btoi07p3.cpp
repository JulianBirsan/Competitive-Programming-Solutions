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

const int MAX=1000001;
int arr[MAX];
int num[MAX];
set<int> cur;
set<int> neg;
queue<int> q;

int main(){
    IOS; fill(num);
    int n,m,c; scan(n,m,c);
    FOR(i,0,n) scan(arr[i]);
    if(m>n){
        cout<<"NONE\n";
        exit(0);
    }
    FOR(i,0,m){
        cur.insert(arr[i]);
        neg.insert(-arr[i]);
        q.push(arr[i]);
        num[arr[i]]++;
    }
    int at=m;
    int out=0;
    while(at<=n){
        int low=*cur.begin();
        int high=abs(*neg.begin());
        if(high-low<=c){
            cout<<at-m+1<<"\n";
            out++;
        }
        int rem=q.front(); q.pop();
        num[rem]--;
        if(num[rem]==0){
            cur.erase(cur.find(rem)); neg.erase(neg.find(-rem));
        }
        q.push(arr[at]); cur.insert(arr[at]); neg.insert(-arr[at]); num[arr[at]]++;
        at++;
    }
    if(out==0) cout<<"NONE\n";
}