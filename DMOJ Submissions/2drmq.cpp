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

int log(int x){
	return 32-__builtin_clz(x)-1;
}

int Sparse[10][1000][10][1000];

void init(std::vector<std::vector<int> > arr){
	int n=arr[0].size();
	for(int ir=0;ir<n;ir++){
		for(int ic=0;ic<n;ic++){
			Sparse[0][ir][0][ic]=arr[ir][ic];
		}
		for(int jc=1;jc<=log(n);jc++){
			for(int ic=0;ic+(1<<(jc-1))<n;ic++){
				Sparse[0][ir][jc][ic]=min(Sparse[0][ir][jc-1][ic],Sparse[0][ir][jc-1][ic+(1<<(jc-1))]);
			}
		}
	}
	for(int jr=1;jr<=log(n);jr++){
		for(int ir=0;ir+(1<<(jr-1))<n;ir++){
			for(int jc=0;jc<=log(n);jc++){
				for(int ic=0;ic<n;ic++){
					Sparse[jr][ir][jc][ic]=min(Sparse[jr-1][ir][jc][ic],Sparse[jr-1][ir+(1<<(jr-1))][jc][ic]);
				}
			}
		}
	}
}

int query(int a, int b, int c, int d){
	int lenx=b-a+1;
	int kx=log(lenx);
	int leny=d-c+1;
	int ky=log(leny);
	int min1=min(Sparse[kx][a][ky][c],Sparse[kx][a][ky][d+1-(1<<ky)]);
	int min2=min(Sparse[kx][b+1-(1<<kx)][ky][c],Sparse[kx][b+1-(1<<kx)][ky][d+1-(1<<ky)]);
	return min(min1,min2);
}

int main(){

}