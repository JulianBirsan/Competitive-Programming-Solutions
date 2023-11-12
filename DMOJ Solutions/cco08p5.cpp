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

vb dp;
int C[100],K[100];

int util(int num, int floor, int start){
	floor = max(0,floor-start);
	int div = floor/num;
	if(num*div<floor){
		num = num*div+num;
	}
	else num = num*div;
	return num+start;
}

int main(){
	int total = 0;
	int lim = 0;
	int n; scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d %d",&K[i],&C[i]);
		total += C[i]*K[i];
	}
	dp.push_back(true);
	int out = total;
	for(int i = 1; i <= total; i++){
		dp.push_back(false);
	}
	for(int i = 0; i < n; i++){
		int c = C[i]; int k = K[i];
		vb temp = dp;
		for(int j = 0; j <= total-lim; j++){
			if(dp[j]){
				int prev = MAXN;
				for(int it = util(c,lim,j); it <= min(j+k*c,total-lim); it+=c){
					temp[it] = true;
					out = min(out,abs(total-it-it));
					int small = min(total-it,it);
					lim = max(lim,small);
					if(abs(total-it-it)>prev){
						break;
					}
					else{
						prev = abs(total-it-it);
					}
				}
			}
		}
		dp = temp;
	}
	cout << out << "\n";
}