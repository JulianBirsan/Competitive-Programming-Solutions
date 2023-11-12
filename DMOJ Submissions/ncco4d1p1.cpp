#include <bits/stdc++.h>   

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;


multiset<int> mn;

int n,x,p,q;
ll ans;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        mn.insert(x);
    }
    while(!mn.empty()){
        q=*mn.begin();
        mn.erase(mn.find(q));
        p=mn.empty()?0:*mn.begin();
        if(!mn.empty()) mn.erase(mn.find(p));
        ans+=(p+q);
        if(!mn.empty()) mn.insert(p+q);
    }
    cout<<ans<<"\n";
}