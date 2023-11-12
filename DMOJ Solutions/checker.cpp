#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=3e3+5;

ll bit[mxN][mxN][2],n,m,r1,c1,r2,c2,q,x,arr[mxN][mxN];

void update(int val,int r,int c,int t){
    r--; c--;
    for(int i=r;i<m;i=i|(i+1)){
        for(int j=c;j<n;j=j|(j+1)){
            bit[i][j][t]+=val;
        }
    }
}

ll query(int r,int c,int t){
    r--; c--;
    ll ret=0;
    for(int i=r;i>=0;i=(i&(i+1))-1){
        for(int j=c;j>=0;j=(j&(j+1))-1){
            ret+=bit[i][j][t];
        }
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>m>>n;
    cin>>q;
    while(q){
        if(q==1){
            cin>>r1>>c1>>x;
            update(x-arr[r1][c1],r1,c1,(r1+c1)&1);
            arr[r1][c1]=x;
        } else{
            cin>>r1>>c1>>r2>>c2;
            ll add=query(r2,c2,(r1+c1)&1)-query(r2,c1-1,(r1+c1)&1)-query(r1-1,c2,(r1+c1)&1)+query(r1-1,c1-1,(r1+c1)&1);
            ll sub=query(r2,c2,((r1+c1)&1)^1)-query(r2,c1-1,((r1+c1)&1)^1)-query(r1-1,c2,((r1+c1)&1)^1)+query(r1-1,c1-1,((r1+c1)&1)^1);
            cout<<add-sub<<"\n";
        }
        cin>>q;
    }
}