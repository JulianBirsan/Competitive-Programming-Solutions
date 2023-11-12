#include <bits/stdc++.h>  

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

char a[10],b[10],c[5];
int x;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>a>>b>>x;
    while(x--){
        cin>>c;
        bool check=true;
        for(int i=0;i<5;i++){
            int cnt=0;
            cnt+=a[i<<1]==c[i]|a[i<<1|1]==c[i];
            cnt+=b[i<<1]==c[i]|b[i<<1|1]==c[i];
            if(c[i]>'F'&&cnt<2) check=false;
            if(c[i]<'F'&&cnt==0) check=false;
        }
        cout<<(check?"Possible baby.\n":"Not their baby!\n");
    }
}