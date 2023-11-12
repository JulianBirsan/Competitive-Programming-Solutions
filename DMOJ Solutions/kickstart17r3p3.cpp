#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,Q,sc[3],dp[55][55][55][55];
string arr[3];

int rec(int at,int s1,int s2,int q,int ret){
    // cout<<at<<" "<<s1<<" "<<s2<<" "<<ret<<" "<<dp[at][s1][s2]<<"\n";
    int a=arr[0][at]=='F';
    int b=arr[1][at]=='F';
    int c=arr[2][at]=='F';
    if(s1<0 || s2<0) return 0;
    if(at==q) return (s1==0 && s2==0 ? ret:0);
    if(dp[at][s1][s2][ret]!=-1) return dp[at][s1][s2][ret];
    return dp[at][s1][s2][ret]=max(rec(at+1,s1-a,s2-b,q,ret+c),
               rec(at+1,s1-(a^1),s2-(b^1),q,ret+(c^1)));
}

int solve(){
    cin>>n>>Q;
    for(int i=0;i<=n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cin>>sc[i];
    if(n==1){
        int same=0;
        for(int i=0;i<Q;i++) same+=arr[0][i]==arr[n][i];
        return Q-(abs(same-sc[0]));   
    }
    memset(dp,-1,sizeof(dp));
    return rec(0,sc[0],sc[1],Q,0);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int testc; cin>>testc;
    for(int i=1;i<=testc;i++){
        cout<<"Case #"<<i<<": "<<solve()<<"\n";
    }
}