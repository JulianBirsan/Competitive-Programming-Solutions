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

bool colour(int n, vector<vi> graph, int k){
	int filled[k+1]; memset(filled,0,sizeof(filled));
	for(int i = 1; i <= k+1; i++){
//		for(int j = 1; j <= k; j++){
//			cout << filled[j] << " ";
//		}
//		cout << "\n";
		for(int c = 1; c <= n; c++){
			bool check = true;
			for(auto u: graph[i]){
				if(filled[u]==c){
					check = false;
					break;
				}
			}
			if(check){
				filled[i] = c;
				break;
			}
			if(c==n) return false;
		}
	}
	return true;
}

int main(){
	for(int t = 0; t < 5; t++){
		int k; scanf("%d",&k);
		vector<vi> graph; vi temp;
		for(int i = 0; i <= k+1; i++) graph.push_back(temp);
		int x,y;
		for(int i = 0; i < k; i++){
			scanf("%d %d",&x,&y);
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		int ans = 0;
		for(int n = 1; n <= 4; n++){
			if(colour(n,graph,k)){
				ans = n;
				break;
			}
			if(n==4) ans = 0;
		}
		cout << ans << "\n";
	}
}