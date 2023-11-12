#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;


int n;
vector<int> arr(6);
set<vector<int> > st;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int k=0;k<n;k++){
        vector<vector<int> > srt;
        for(int i=0;i<6;i++){
            cin>>arr[i];
        }
        for(int i=0;i<6;i++){
            srt.push_back(arr);
            vector<int> temp=arr;
            reverse(temp.begin(),temp.end());
            srt.push_back(temp);
            arr.push_back(arr[0]);
            arr.erase(arr.begin());
        }
        sort(srt.begin(),srt.end());
        st.insert(srt[0]);
    }
    cout<<(st.size()<n?"Twin snowflakes found.\n":"No two snowflakes are alike.\n");
}