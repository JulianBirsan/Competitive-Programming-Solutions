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

vector<vi> ldb;
vector<vi> prb;

int main(){
	int n,t,p;
	scanf("%d %d %d",&n,&t,&p);
	for(int i = 0; i < n; i++){
		vi temp;
		temp.push_back(0); temp.push_back(0); temp.push_back(-(i+1));
		ldb.push_back(temp);
	}
	for(int i = 0; i < t; i++){
		vi te;
		prb.push_back(te);
	}
	bool x;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < t; j++){
			cin >> x;
			if(x){
				prb[j].push_back(i);
				ldb[i][1]++;
			}
		}
	}
	for(int i = 0; i < prb.size(); i++){
		for(auto u: prb[i]){
			ldb[u][0] += n-prb[i].size();
		}
	}
	sort(ldb.rbegin(),ldb.rend());
	for(int i = 0; i < ldb.size(); i++){
		if(abs(ldb[i][2])==p){
			cout << ldb[i][0] << " " << i+1 << "\n";
			exit(0);
		}
	}
}