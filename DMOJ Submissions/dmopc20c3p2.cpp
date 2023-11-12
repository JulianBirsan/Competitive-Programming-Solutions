#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

unordered_map<int,int> thing[20];
vector<pii> nts[20];
ll ans=0;

int n,m,k,a;

int main(){
    scanf("%d%d%d",&m,&n,&k);
    
    for(int i=0;i<m;i++){
        int prev=-1;
        for(int j=0;j<n;j++){
            scanf("%d",&a);
            if(j>=1){
                nts[j].push_back(pii(prev,a));
            }
            prev=a;
        }
    }
    for(int i=1;i<n;i++){
        sort(nts[i].begin(),nts[i].end());
        for(pii &u:nts[i]){
            // cout<<"u: "<<u.first<<" "<<u.second<<"\n";
            auto f=lower_bound(nts[i].begin(),nts[i].end(),pii(u.first+k,u.second));
            // cout<<"f: "<<f->first<<" "<<f->second<<"\n";
            ans+=(f->first==u.first+k && f->second==u.second+k);
        }
        // cout<<"\n";
    }
    cout<<ans<<"\n";
}