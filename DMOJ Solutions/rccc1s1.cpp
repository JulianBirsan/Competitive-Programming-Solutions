#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

set<char> vow;


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    vow.insert('a'); vow.insert('e'); vow.insert('i'); 
    vow.insert('o'); vow.insert('y'); vow.insert('u');
    int n,c,v;
    cin>>n>>c>>v;
    string s; cin>>s;
    int vc=0,cc=0;
    for(int i=0;i<n;i++){
        if(vow.count(s[i])){
            if(cc>c){
                cout<<"NO\n";
                return 0;
            }
            if(s[i]!='y') cc=0;
            vc++;
        } 
        if(vow.count(s[i])==0 || s[i]=='y'){
            if(vc>v){
                cout<<"NO\n";
                return 0;
            }
            if(s[i]!='y') vc=0;
            cc++;
        }
    }
    if(vc>v || cc>c){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
}