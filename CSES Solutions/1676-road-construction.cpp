#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=1e5+5;

int uf[mxN],n,m,a,b;

int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);}
bool same(int x,int y){return find(x)==find(y);}
void unite(int x,int y){
    x=find(x); y=find(y);
    if(uf[x]>uf[y])
        swap(x,y);
    uf[x]+=uf[y]; uf[y]=x;
}

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    //COMMENT THIS OUT
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin>>n>>m;
    int num=n; int big=1;
    memset(uf,-1,sizeof(uf));
    while(m--){
        cin>>a>>b;
        if(!same(a,b)){
            num--;
            unite(a,b);
            big=max(big,abs(uf[find(a)]));
            big=max(big,abs(uf[find(b)]));
        }
        cout<<num<<" "<<big<<"\n";
    }
}

//dp?
//graph?
//compress + bit?
//bsearch?