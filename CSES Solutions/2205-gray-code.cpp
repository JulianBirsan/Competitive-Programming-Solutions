#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cerr<<vars<<" = ";
    string delim="";
    (...,(cerr<<delim<<values,delim=", "));
    cerr<<"\n";
}
#else
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {}
#endif

#define pb push_back
#define sz(x) (int)(x.size())
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> inline void maxa(T& a,T b){a=max(a,b);}
template<typename T> inline void mina(T& a,T b){a=min(a,b);} 

vector<int> graph[1<<16];
int n,seen[1<<16];
vector<int> order;

void print(int x){
    for(int i=0;i<n;i++){
        if(x&(1<<i))
            cout<<1;
        else
            cout<<0;
    }
    cout<<"\n";
}

void topsort(int at){
    seen[at]=1;
    for(int &i:graph[at]){
        if(!seen[i])
            topsort(i);
    }
    order.pb(at);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            graph[i].pb(i^(1<<j));
        }
    }
    for(int i=0;i<(1<<n);i++){
        if(!seen[i])
            topsort(i);
    }
    reverse(order.begin(),order.end());
    for(int &i:order)
        print(i);
}
