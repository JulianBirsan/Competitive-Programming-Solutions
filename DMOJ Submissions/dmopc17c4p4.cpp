#include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    typedef pair<int,int> pii;
    typedef pair<ll,ll> pll;


    void solve(){
        int n; cin>>n;
        vector<int> a(n),deg(n+1),seen(n+1);
        for(int &i:a){
            cin>>i;
            deg[i]++;
        }
        set<pii> q;
        for(int i=1;i<=n;i++){
            q.insert(pii(-deg[i],i));
        }
        int j=0;
        int plus=1;
        vector<int> ans;
        for(int i=0;i<n;i++){
            pii fst=*q.begin();
            if(a[i]!=fst.second){
                ans.push_back(fst.second);
                q.erase(fst);
            } else{
                if(q.size()>1){
                    pii sec=*++q.begin();
                    q.erase(sec);
                    ans.push_back(sec.second);
                }
            }
            if(q.count(pii(-deg[a[i]],i))){
                q.erase(pii(-deg[a[i]],i));
                deg[a[i]]--;
                q.insert(pii(-deg[a[i]],i));
            }
        }
        if(ans.size()<n){
            cout<<-1<<"\n";
        } else{
            for(int &i:ans)
                cout<<i<<" ";
            cout<<"\n";
        }
    }

     
    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
     
        #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif
     
        int t=1;
        while(t--) solve();
    }