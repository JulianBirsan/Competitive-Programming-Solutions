#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;

void solve(){
	int s; scanf("%d",&s);
	vector<vi> scores;
	vector<vector<vi> > groups;
	string str;
	for(int i=0;i<s;i++){
		cin>>str;
		int ind=str.find('-');
		int x=stoi(str.substr(0,ind));
		int y=stoi(str.substr(ind+1));
		vi temp; temp.push_back(x); temp.push_back(y);
		temp.push_back(i); if(temp[0]<temp[1]) swap(temp[0],temp[1]);
		scores.push_back(temp);
	}
	sort(scores.begin(),scores.end());
	for(vi cur:scores){
		bool check=true;
		for(int i=0;i<groups.size();i++){
			int c=0;
			for(int j=0;j<groups[i].size();j++){
				if((cur[0]>=groups[i][j][0]&&cur[1]>=groups[i][j][1]) || (cur[0]<=groups[i][j][0]&&cur[1]<=groups[i][j][1])){
					c++;
				}
			}
			if(c==groups[i].size()){
				check=false;
				groups[i].push_back(cur);
				break;
			}
		}
		if(check){
			vector<vi> temp;
			temp.push_back(cur);
			groups.push_back(temp);
		}
	}
	cout<<groups.size()<<"\n";
	for(vector<vi> group: groups){
		for(vi score: group){
			cout<<score[0]<<"-"<<score[1]<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++){
		solve();
	}
}