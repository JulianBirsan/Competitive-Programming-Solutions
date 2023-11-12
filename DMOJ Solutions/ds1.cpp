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

int arr[100001],arr2[100001];
ll bit[100001],num[100001];

void update(int val,int ind,int n){
    //ind++;
    while(ind<=n){
        bit[ind]+=val;
        ind+=ind&(-ind);
    }
}

void updateNum(int val,int ind,int n){
    //ind++;
    while(ind<=n){
        num[ind]+=val;
        ind+=ind&(-ind);
    }
}

ll getSumBit(int ind){
    ll ret=0;
    //ind++;
    while(ind>0){
        ret+=bit[ind];
        ind-=ind&(-ind);
    }
    return ret;
}

int getSumNum(int ind){
    int ret=0;
    //ind++;
    while(ind>0){
        ret+=num[ind];
        ind-=ind&(-ind);
    }
    return ret;
}

int main(){
    IOS; fill(arr); fill(bit); fill(num); fill(arr2);
    int n,m; scan(n,m);
    FOR(i,1,n+1) {
        scan(arr[i]); arr2[arr[i]]++;
    }
    FOR(i,1,n+1){
        update(arr[i],i,n);
        updateNum(1,arr[i],100000);
    }
    char q; int x,v,l,r;
    FOR(i,0,m){
        scan(q);
        if(q=='C'){
            scan(x,v);
            updateNum(-1,arr[x],100000);
            updateNum(1,v,100000);
            update(v-arr[x],x,n);
            arr[x]=v;

        } else if(q=='S'){
            scan(l,r);
            cout<<getSumBit(r)-getSumBit(l-1)<<"\n";
        } else{
            scan(v);
            cout<<getSumNum(v)<<"\n";
        }
    }
}