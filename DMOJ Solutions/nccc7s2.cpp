#include <bits/stdc++.h>  

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;

long double x1,Y1,x2,Y2,x,y;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>x>>y>>x1>>Y1>>x2>>Y2;
    
    long double ans=1e9;
    if(x>=x1 && x<=x2){
        if(y<Y1){
            ans=Y1-y-0.00001;
        } else{
            ans=y-Y2-0.00001;
        }
    } else if(y<=Y2 && y>=Y1){
        if(x<x1){
            ans=x1-x-0.00001;
        } else{
            ans=x-x2-0.00001;
        }
    } else{
        if(x<x1 && y<Y1){
            ans=sqrt((x1-x)*(x1-x)+(Y1-y)*(Y1-y))-0.00001;
        } else if(x<x1 && y>Y2){
            ans=sqrt((x1-x)*(x1-x)+(y-Y2)*(y-Y2))-0.00001;
        } else if(x>x2 && y<Y1){
            ans=sqrt((x-x2)*(x-x2)+(Y1-y)*(Y1-y))-0.00001;
        } else{
            ans=sqrt((x-x2)*(x-x2)+(y-Y2)*(y-Y2))-0.00001;
        }
    }
    cout<<fixed<<setprecision(3)<<ans<<"\n";
}