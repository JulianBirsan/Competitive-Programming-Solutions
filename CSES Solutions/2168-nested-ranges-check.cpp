#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxN=2e5+5;

struct trip{
    int l,r,i;
};

int n,a,b,ans[mxN][2];
vector<trip> rng;

bool comp(trip a,trip b){
    if(a.l<b.l) return 1;
    if(b.l<a.l) return 0;
    return a.r>b.r;
}

bool inv(trip a,trip b){
    if(a.l<b.l) return 0;
    if(b.l<a.l) return 1;
    return a.r<b.r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        rng.push_back((trip){a,b,i});
    }
    sort(rng.begin(),rng.end(),comp);
    set<int> pos;
    for(int i=0;i<n;i++){
        if(i==0){
            if(rng[i+1].l==rng[i].l && rng[i+1].r==rng[i].r){
                ans[rng[i].i][0]=1;
            }
        } else{
            int x=*pos.rbegin();
            if(x>=rng[i].r){
                ans[rng[i].i][0]=1;
            }
        }
        pos.insert(rng[i].r);
    }
    pos.clear();
    sort(rng.begin(),rng.end(),inv);
    for(int i=0;i<n;i++){
        if(i==0){
            if(rng[i+1].l==rng[i].l && rng[i+1].r==rng[i].r){
                ans[rng[i].i][1]=1;
            }
        } else{
            int x=*pos.begin();
            if(x<=rng[i].r){
                ans[rng[i].i][1]=1;
            }
        }
        pos.insert(rng[i].r);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i][1]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<ans[i][0]<<" ";
    cout<<"\n";
}