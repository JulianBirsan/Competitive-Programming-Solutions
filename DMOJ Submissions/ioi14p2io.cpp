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

const int mx=2e6+1;

struct node{
    int flr,cl,def;
    bool lazy;
};

node st[4*mx];

void push(int v){
    if(!st[v].lazy) return;
    if(st[v].def!=-1){
        st[v<<1].def=st[v<<1|1].def=st[v].def;
        st[v<<1].flr=st[v<<1|1].flr=0;
        st[v<<1|1].cl=st[v<<1|1].cl=MAXN;
    } else{
        if(st[v<<1].def!=-1){
            st[v<<1].def=max(st[v<<1].def,st[v].flr);
            st[v<<1].def=min(st[v<<1].def,st[v].cl);
        }
        else if(st[v].flr>=st[v<<1].cl){
            st[v<<1].cl=MAXN;
            st[v<<1].flr=0;
            st[v<<1].def=st[v].flr;
        } else if(st[v].cl<=st[v<<1].flr){
            st[v<<1].cl=MAXN;
            st[v<<1].flr=0;
            st[v<<1].def=st[v].cl;
        } else{
            st[v<<1].cl=min(st[v<<1].cl,st[v].cl);
            st[v<<1].flr=max(st[v<<1].flr,st[v].flr);
        }
        if(st[v<<1|1].def!=-1){
            st[v<<1|1].def=max(st[v<<1|1].def,st[v].flr);
            st[v<<1|1].def=min(st[v<<1|1].def,st[v].cl);
        }
        else if(st[v].flr>=st[v<<1|1].cl){
            st[v<<1|1].cl=MAXN;
            st[v<<1|1].flr=0;
            st[v<<1|1].def=st[v].flr;
        } else if(st[v].cl<=st[v<<1|1].flr){
            st[v<<1|1].cl=MAXN;
            st[v<<1|1].flr=0;
            st[v<<1|1].def=st[v].cl;
        } else{
            st[v<<1|1].cl=min(st[v<<1|1].cl,st[v].cl);
            st[v<<1|1].flr=max(st[v<<1|1].flr,st[v].flr);
        }
    }
    st[v].lazy=false;
    st[v].flr=0; st[v].cl=MAXN; st[v].def=-1;
    st[v<<1].lazy=st[v<<1|1].lazy=true;
}

void build(int v,int l,int r){
    if(l==r) st[v]=(node){0,MAXN,0,0};
    else{
        int m=(l+r)>>1;
        build(v<<1,l,m);
        build(v<<1|1,m+1,r);
        st[v]=(node){0,MAXN,-1,0};
    }
}

void update(int v,int l,int r,int lq,int rq,int op,int val){
    if(l<r) push(v);
    if(lq>rq) return;
    if(l>=lq&&r<=rq){
        st[v].lazy=true;
        if(op==1){
            if(st[v].cl<=val){
                st[v].cl=MAXN;
                st[v].flr=0;
                st[v].def=val;
            } else if(st[v].def!=-1) st[v].def=max(st[v].def,val);
            else st[v].flr=max(st[v].flr,val);
        } else{
            if(st[v].flr>=val){
                st[v].flr=0;
                st[v].cl=MAXN;
                st[v].def=val;
            } else if(st[v].def!=-1) st[v].def=min(st[v].def,val);
            else st[v].cl=min(st[v].cl,val);
        }
//        cout<<l<<"->"<<r<<": "<<st[v].flr<<"->"<<st[v].cl<<" "<<st[v].def<<"\n";
        if(l<r) push(v);
    } else{
        int m=(l+r)>>1;
//        cout<<l<<"->"<<r<<": "<<st[v].flr<<"->"<<st[v].cl<<" "<<st[v].def<<"\n";
        update(v<<1,l,m,lq,min(m,rq),op,val);
        update(v<<1|1,m+1,r,max(lq,m+1),rq,op,val);
    }
}

void print(int v,int l,int r){
//    cout<<l<<"->"<<r<<": "<<st[v].flr<<"->"<<st[v].cl<<" "<<st[v].def<<"\n";
//    if(l==4&&r==5){
//        cout<<st[v<<1|1].flr<<" "<<st[v<<1|1].cl<<" "<<st[v<<1|1].def<<"\n";
//    }
    if(l==r) cout<<st[v].def<<"\n";
    else{
        push(v);
        int m=(l+r)>>1;
        print(v<<1,l,m);
        print(v<<1|1,m+1,r);
    }
}

int n,k,op,l,r,h;

int main(){
    IOS;
    scan(n,k);
    build(1,1,n);
    while(k--){
        scan(op,l,r,h);
        l++; r++;
        update(1,1,n,l,r,op,h);
    }
    print(1,1,n);
}