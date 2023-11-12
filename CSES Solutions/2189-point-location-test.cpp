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

struct vector2D{
    ll x,y;
    vector2D(){
        x = y = 0;
    }
    vector2D(ll _x,ll _y){
        x = _x,y = _y;
    }
    double magnitude(){
        return sqrt((double)x*x+y*y);
    }
    ll cross(const vector2D&v){
        return x*v.y-v.x*y;
    }
    void operator = (const vector2D&v){
      x = v.x;
      y = v.y;
    }
    vector2D operator + (const vector2D&v){ 
        return (vector2D){x+v.x,y+v.y};
    }
    //vector subtraction
    vector2D operator - (const vector2D&v){
        return (vector2D){x-v.x,y-v.y};
    }
    ll operator ^ (const vector2D&v){
        return x*v.x + y*v.y;
    }
};

const double EPS=0.0000000001;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t; cin>>t;
    while(t--){
        ll a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        vector2D v1={a,b};
        vector2D v2={c,d};
        vector2D v3={e,f};
        vector2D v4=v2-v1;
        vector2D v5=v3-v1;
        ll cr=v4.cross(v5);
        if(cr<0)
            cout<<"RIGHT\n";
        else if(cr>0)
            cout<<"LEFT\n";
        else
            cout<<"TOUCH\n";
    }
}
