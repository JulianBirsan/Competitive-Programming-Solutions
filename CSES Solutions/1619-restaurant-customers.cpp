#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

priority_queue<int,vector<int>,greater<int> > in,out;

int n,a,b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin>>n;
    int cnt=0;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        in.push(a);
        out.push(b);
    }
    while(!in.empty()){
        if(in.top()<out.top()){
            cnt++;
            in.pop();
        } else{
            cnt--;
            out.pop();
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<"\n";
}