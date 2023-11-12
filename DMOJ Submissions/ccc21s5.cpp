#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxN=15e4+5;

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

int psa[mxN][17],st[4*mxN],n,m,q[mxN][3],arr[mxN];

void build(int v,int l,int r){
    if(l==r) st[v]=arr[l];
    else{
        int m=(l+r)>>1;
        build(v<<1,l,m);
        build(v<<1|1,m+1,r);
        st[v]=gcd(st[v<<1],st[v<<1|1]);
    }
}

int query(int v,int l,int r,int lq,int rq){
    if(lq>rq) return 0;
    if(l>=lq&&r<=rq) return st[v];
    int m=(l+r)>>1;
    return gcd(query(v<<1,l,m,lq,min(rq,m)),query(v<<1|1,m+1,r,max(lq,m+1),rq));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>q[i][0]>>q[i][1]>>q[i][2];
        psa[q[i][0]][q[i][2]]++;
        psa[q[i][1]+1][q[i][2]]--;
    }
    for(int i=1;i<=n;i++){
        arr[i]=1;
        for(int j=1;j<=16;j++){
            psa[i][j]+=psa[i-1][j];
            if(psa[i][j]){
                if(arr[i]%j==0) continue;
                int div=gcd(arr[i],j);
                arr[i]*=(j/div);
            }
        }
    }
    build(1,1,n);
    for(int i=0;i<m;i++){
        if(query(1,1,n,q[i][0],q[i][1])!=q[i][2]){
            cout<<"Impossible\n";
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}