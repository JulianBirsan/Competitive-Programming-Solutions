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

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define read(v,n) for(int i=0;i<n;i++) scan(v[i])
#define fill(x) memset(x,0,sizeof(x))
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<long long int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;
typedef pair<string,double> psd;
typedef unordered_set<int> usi;
typedef multiset<int> msi;
typedef unordered_map<int,int> umii;
typedef double db;
typedef long double ld;

const int mx=1e7;

int n,m,ans[mx];
bool mag[mx];
string s,temp;

queue<int> q;

int ocnt=0,ccnt=0;

int main(){
    IOS;
    fill(ans);
    scan(n,m);
    while(s.length()<n){
        scan(temp);
        s+=temp;
    }
    FOR(i,0,n){
        ocnt+=s[i]=='(';
        ccnt+=s[i]!='(';
        mag[i]=s[i]==']';
    }
    if(ccnt>ocnt){
        cout<<"0\n";
        return 0;
    }
    if(m==0){
        cout<<"1\n";
        return 0;
    }
    reverse(rng(s));
    ocnt=ccnt=0;
    int ind=0;
    FOR(i,0,n){
        if(s[i]==']'){
            ind=i;
            if(ccnt<0){
                cout<<"0\n";
                return 0;
            }
            break;
        }
        ccnt-=s[i]=='(';
        ccnt+=s[i]!='(';
    }
    FOR(i,ind,n){
        if(s[i]==']') {
            q.push(n-i-1);
        }
        else if(s[i]==')') {
            ccnt++;
        }
        else{
            if(ccnt==0){
                ans[q.front()]++;
                if(q.size()>1) q.pop();
            } else ccnt--;
        }
    }
    ccnt=0,ocnt=0;
    reverse(rng(s));
    FOR(i,0,n){
        if(mag[i]&&ans[i]==0){
            cout<<"0\n";
            return 0;
        }
        ocnt+=s[i]=='(';
        ccnt+=s[i]==')';
        if(mag[i]) ccnt+=ans[i];
    } 
    if(ocnt!=ccnt){
        cout<<"0\n";
        return 0;
    }
    cout<<1<<"\n";
    FOR(i,0,n){
        if(mag[i]) cout<<ans[i]<<"\n";
    }
}