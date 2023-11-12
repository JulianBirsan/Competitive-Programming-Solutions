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

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n; cin>>n;
    vector<int> a(n-2),cnt(n+1);
    for(int &i:a){
        cin>>i;
        cnt[i]++;
    }
    priority_queue<int,vector<int>,greater<int>> q,q2;
    for(int i=1;i<=n;i++){
        if(!cnt[i])
            q.push(i);
    }
    for(int i=0;i<n-2;){
        while(i<n-2){
            cout<<q.top()<<" "<<a[i]<<"\n";
            q.pop();
            cnt[a[i]]--;
            if(!cnt[a[i]]){
                deb(a[i]);
                q.push(a[i]);
            }
            i++;
        }
    }
    q2.push(q.top());
    q.pop();
    cout<<q.top()<<" "<<q2.top()<<"\n";
}
