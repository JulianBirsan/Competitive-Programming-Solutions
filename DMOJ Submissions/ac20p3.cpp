#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<int> oc[26];

string s,t;
ll ls,lt;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>ls>>lt;
    cin>>s>>t;
    for(int i=0;i<ls;i++){
        oc[s[i]-'a'].push_back(i);
    }
    ll prev=-1;
    ll total=0;
    for(int i=0;i<lt;i++){
        if(oc[t[i]-'a'].size()==0){
            cout<<-1<<"\n";
            return 0;
        }
        if(oc[t[i]-'a'].back()<=prev){
            total++;
            prev=oc[t[i]-'a'][0];
        } else{
            prev=*lower_bound(oc[t[i]-'a'].begin(),oc[t[i]-'a'].end(),prev+1);
        }
    }
    cout<<total*ls+prev+1<<"\n";
}