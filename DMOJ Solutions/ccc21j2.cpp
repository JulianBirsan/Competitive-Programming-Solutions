#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct guy{
    int v,j;
    string s;
};

bool comp(guy a,guy b){
    if(a.v>b.v) return true;
    if(b.v>a.v) return false;
    return a.j<b.j;
}

vector<guy> arr;

int n,b;

string nm;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nm>>b;
        arr.push_back((guy){b,i,nm});
    }     
    sort(arr.begin(),arr.end(),comp);
    cout<<arr[0].s<<"\n";
}