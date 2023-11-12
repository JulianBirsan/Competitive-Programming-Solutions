#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=2e5+5;

int arr[mxN],n,seen[mxN];

vector<int> cur;
vector<vector<int> > ans;

void dfs(int at){
    seen[at]=true;
    cur.push_back(at);
    if(!seen[arr[at]]){
        dfs(arr[at]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=n;i++){
        if(arr[i]==i)
            continue;
        if(!seen[i]){
            dfs(i);
            ans.push_back(cur);
            cur.clear();
        }
    }
    if(ans.size()<=1){
        cout<<ans.size()<<"\n";
        for(vector<int> &v:ans){
            cout<<v.size()<<" ";
            for(int &i:v)
                cout<<i<<" ";
            cout<<"\n";
        }
    } else{
        cout<<"2\n";
        vector<int> all;
        for(vector<int> &v:ans){
            for(int &i:v){
                all.push_back(i);
            }
        }
        cout<<all.size()<<" ";
        for(int &i:all){
            cout<<i<<" ";
        }
        cout<<"\n";
        cout<<ans.size()<<" ";
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i][0]<<" ";
        }
        cout<<"\n";
    }
}