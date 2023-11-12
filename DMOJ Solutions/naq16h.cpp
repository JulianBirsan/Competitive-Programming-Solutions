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

int dph[101][100001];
int dpb[101][100001];
vi H,B;

int main(){
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100001; j++){
			if(j==0) dpb[i][j] = dph[i][j] = 0;
			else dpb[i][j] = dph[i][j] = MAXN;
		}
	}
	int toth = 0;
	int totb = 0;
	int h,b;
	scanf("%d",&h);
	int hi,bi;
	for(int i = 1; i <= h; i++){
		scanf("%d",&hi);
		toth += hi;
		H.push_back(hi);
	}
	scanf("%d",&b);
	for(int i = 1; i <= b; i++){
		scanf("%d",&bi);
		totb += bi;
		B.push_back(bi);
	}
	int out = MAXN;
	for(int i = 1; i <= max(b,h); i++){
		if(i > b){
			for(int j = 1; j <= totb; j++){
				dpb[i][j] = dpb[i-1][j];
			}
		}
		else{
			int val = B[i-1];
			for(int j = 1; j <= totb; j++){
				dpb[i][j] = dpb[i-1][j];
				if(j>=val){
					if(dpb[i-1][j-val] != MAXN) dpb[i][j] = min(dpb[i][j],dpb[i-1][j-val]+1);
				}
			}
		}
	}
	cout << "\n";
	for(int i = 1; i <= max(h,b); i++){
		if(i>h){
			for(int j = 1; j <= toth; j++){
				dph[i][j] = dph[i-1][j];
				if(dph[i][j] != MAXN && dpb[i][j] != MAXN) out = min(out,dpb[i][j] + dph[i][j]);
			}
		}
		else{
			int val = H[i-1];
			for(int j = 1; j <= toth; j++){
				dph[i][j] = dph[i-1][j];
				if(j>=val){
					if(dph[i-1][j-val] != MAXN)	dph[i][j] = min(dph[i][j],dph[i-1][j-val]+1);
				}
				if(dph[i][j] != MAXN && dpb[i][j] != MAXN) out = min(out,dpb[i][j] + dph[i][j]);
			}
		}
	}
	if(out==MAXN) cout << "impossible\n";
	else cout << out << "\n";
}