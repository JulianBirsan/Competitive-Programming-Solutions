#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <map>
#include <bitset>
#include <iomanip>
#include <cstring>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cmath>    

using namespace std;

#define FOR(i,j,n) for(int i=j;i<n;i++)

typedef long long int ll;
typedef pair<int,int> pii;

struct player{
    string id;
    int t;
};

void print(player a,player b){
    if(a.t<b.t) cout<<a.id<<" "<<b.id<<"\n";
    else cout<<b.id<<" "<<a.id<<"\n";
}

queue<string> q;
vector<pair<player,player> > out;
int best,n,w,b;
string s,lg;
player wo,wd,bo,bd;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    FOR(i,0,n){
        cin>>s;
        if(i==0) wo=(player){s,i};
        else if(i==1) bo=(player){s,i};
        else if(i==2) wd=(player){s,i};
        else if(i==3) bd=(player){s,i};
        else q.push(s);
    }
    cin>>lg;
    FOR(i,0,lg.length()){
        //cout<<wo.id<<" "<<wd.id<<" vs. "<<bo.id<<" "<<bd.id<<"\n";
        if(lg[i]=='W'){
            w++;
            swap(wo,wd);
            if(b>best){
                best=b;
                out.clear();
                out.push_back(make_pair(bo,bd));
            } else if(b==best){
                out.push_back(make_pair(bo,bd));
            }
            b=0;
            q.push(bd.id);
            bd=bo;
            bo=(player){q.front(),i+4};
            q.pop();
        } else{
            b++;
            swap(bo,bd);
            if(w>best){
                best=w;
                out.clear();
                out.push_back(make_pair(wo,wd));
            } else if(w==best){
                out.push_back(make_pair(wo,wd));
            }
            w=0;
            q.push(wd.id);
            wd=wo;
            wo=(player){q.front(),i+4};
            q.pop();
        }
    }
    //cout<<"\n";
    if(w>best && lg.back()=='W'){
        best=w;
        out.clear();
        out.push_back(make_pair(wo,wd));
    } else if(w==best && lg.back()=='W'){
        out.push_back(make_pair(wo,wd));
    }
    if(b>best && lg.back()=='B'){
        out.clear();
        out.push_back(make_pair(bo,bd));
    } else if(b==best && lg.back()=='B'){
        out.push_back(make_pair(bo,bd));
    }
    for(pair<player,player> i : out){
        print(i.first,i.second);
    }
}