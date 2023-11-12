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

int cst[100],wt[2001],prk[2001];

int main(){
	int res = 0;
	set<int> stk;
	queue<int> q;
	int n,m; scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d",&cst[i]);
		stk.insert(i);
	}
	for(int i = 0; i < m; i++){
		scanf("%d",&wt[i+1]);
	}
	int x;
	for(int i = 0; i < 2*m; i++){
		scanf("%d",&x);
		if(x>0){
			if(stk.size()==0) q.push(x);
			else{
				int p = *stk.begin();
				res += cst[p]*wt[x];
				prk[x] = p;
				stk.erase(stk.find(p));
			}
		}
		else{
			x = abs(x);
			if(q.size()>0){
				int at = q.front(); q.pop();
				prk[at] = prk[x];
				res += cst[prk[x]]*wt[at];
			}
			else{
				stk.insert(prk[x]);
			}
		}
	}
	cout << res << "\n";
}