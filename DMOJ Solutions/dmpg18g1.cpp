#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=1e6+5;

stack<int> stk;

int arr[mxN],pp[mxN],n,k,x;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>x;
        arr[x]=1;
    }
    for(int i=0;i<=k;i++){
        cin>>x;
        pp[x]=i+1;
    }
    int cnt=0;
    int i=1;
    while(cnt<k){
        i=max(i,0);
        if(pp[i]){
            stk.push(pp[i]);
            pp[i]=0;
        }
        if(arr[i] && !stk.empty()){
            stk.pop();
            arr[i]=0;
            cnt++;
        }
        i=(i+1)%(n+1);
    }
    cout<<stk.top()<<"\n";
}