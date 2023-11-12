#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string s;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>s;
    int prev=0;
    while(s!="99999"){
        string ins=s.substr(0,2);
        string rest=s.substr(2,3);
        int dist=stoi(rest);
        int a=ins[0]-'0';
        int b=ins[1]-'0';
        if(a+b==0){
            if(prev) cout<<"right "<<dist<<"\n";
            else cout<<"left "<<dist<<"\n";
        } else if((a+b)&1){
            cout<<"left "<<dist<<"\n";
            prev=0;
        } else{
            cout<<"right "<<dist<<"\n";
            prev=1;
        }
        cin>>s;
    }
}