#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string s;

int a,b,c;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>s;
    for(char &i:s){
        a+=i=='L';
        b+=i=='M';
    }
    int ans=0;
    int add=0,add2=0;
    for(int i=0;i<a;i++){
        ans+=s[i]!='L';
    }
    for(int i=a;i<a+b;i++){
        add+=s[i]=='S';
    }
    for(int i=a+b;i<s.length();i++){
        add2+=s[i]=='M';
    }
    cout<<ans+max(add,add2)<<"\n";
}