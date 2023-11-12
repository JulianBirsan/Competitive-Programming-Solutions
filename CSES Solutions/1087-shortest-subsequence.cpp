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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mxN=2e5+5; //make sure this is right
const int mod=1e9+7;

vector<int> nxt[4];
int id[1000];
char rev[4]={'A','C','T','G'};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    string s; cin>>s;
    id['A'] = 0;
    id['C'] = 1;
    id['T'] = 2;
    id['G'] = 3;
    for(int i=0;i<sz(s);i++){
        nxt[id[s[i]]].pb(i);
    }
    int cur=0;
    string ans="";
    while(cur<sz(s)){
        int go=-1; char let='*';
        for(int i=0;i<4;i++){
            if(!sz(nxt[i]) || cur>nxt[i].back()){
                go=sz(s); let=rev[i];
            } else{
                if(*lower_bound(nxt[i].begin(),nxt[i].end(),cur)>go){
                    go=*lower_bound(nxt[i].begin(),nxt[i].end(),cur);
                    let=rev[i];
                }
            }
        }
        ans+=let;
        cur=go+1;
    }
    if(cur==sz(s))
        ans+='A';
    cout<<ans<<"\n";
}
