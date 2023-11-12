#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string al,s;

set<string> out;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>al>>s;
    for(int i=0;i<al.length();i++){
        for(int j=0;j<s.length();j++){
            string temp=s;
            temp[j]=al[i];
            out.insert(temp);
            temp=s;
            temp.erase(temp.begin()+j);
            out.insert(temp);
            temp=s;
            temp.insert(temp.begin()+j,al[i]);
            out.insert(temp);
        }
        s.push_back(al[i]);
        out.insert(s);
        s.pop_back();
    }
    if(out.count(s)) out.erase(s);
    for(string i:out){
        cout<<i<<"\n";
    }
}