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

string s,key;
int k;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin>>s>>key;
    int m=key.length(),n=s.length();
    FOR(i,0,n){
        if(i<m) k=key[i]-'A';
        else k=s[i-m]-'A';
        if(s[i]-k<'A'){
            k-=(s[i]-'A');
            s[i]='Z'-k;
            s[i]++;
        } else s[i]-=k;
    }
    cout<<s<<"\n";
}