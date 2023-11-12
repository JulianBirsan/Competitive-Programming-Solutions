#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cerr<<vars<<" = ";
    string delim="";
    (...,(cerr<<delim<<values,delim=", "));
    cerr<<"\n";
}
#else
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {}
#endif

#define pb push_back
#define sz(x) (int)(x.size())
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> inline void maxa(T& a,T b){a=max(a,b);}
template<typename T> inline void mina(T& a,T b){a=min(a,b);} 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mxN=2e5+5; //make sure this is right
const int mod=1e9+7;

struct node{
    int pref,suff,all,ans;
    node operator +(const node &o) const{
        node res={0,0,0,0};
        res.all=all+o.all;
        res.pref=pref+(pref==all?o.pref:0);
        res.suff=o.suff+(o.suff==o.all?suff:0);
        res.ans=max(max(ans,o.ans),suff+o.pref);
        return res;
    }
    void flip(){pref^=1;suff^=1;ans^=1;}
};

struct tree{
    node st[4*mxN];
    void build(int v,int l,int r,string &s,char w){
        if(l==r){
            st[v]={s[l-1]==w,s[l-1]==w,1,s[l-1]==w};
        } else{
            int m=(l+r)>>1;
            build(v<<1,l,m,s,w);
            build(v<<1|1,m+1,r,s,w);
            st[v]=st[v<<1]+st[v<<1|1];
        }
    }
    void update(int v,int l,int r,int ind){
        if(l>ind || r<ind) return;
        if(l==r) st[v].flip();
        else{
            int m=(l+r)>>1;
            update(v<<1,l,m,ind);
            update(v<<1|1,m+1,r,ind);
            st[v]=st[v<<1]+st[v<<1|1];
        }
    }
    int ans(){return st[1].ans;}
} tree1,tree2;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    string s; cin>>s;
    int n=sz(s);
    tree1.build(1,1,n,s,'1');
    tree2.build(1,1,n,s,'0');
    int q; cin>>q;
    while(q--){
        int x; cin>>x;
        tree1.update(1,1,n,x);
        tree2.update(1,1,n,x);
        cout<<max(tree1.ans(),tree2.ans())<<" ";
    }
}
