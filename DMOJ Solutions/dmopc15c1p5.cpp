#include <bits/stdc++.h>

using namespace std;

int main(){
	int w,h,n;
	scanf("%i %i %i",&w,&h,&n);
	int grid[h][w], psaVer[w][h+1], psaHor[h][w+1];
	memset(psaVer,0,sizeof(psaVer[0][0])*w*(h+1));
	memset(psaHor,0,sizeof(psaHor[0][0])*h*(w+1));
	int topproduct = 0;
	set<pair<int,int> > factor;
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			if(i*j<=n && i*j<=h*w){
				if(i*j>=topproduct || topproduct-i*j<=50){
					pair<int,int> one(i,j),two(j,i);
					if(i<=h && j<=w){
						if(i*j>topproduct){
							factor.clear(); topproduct = i*j;
						}
						factor.insert(one);
					}
					if(i<=w && j<=h){
						if(i*j>topproduct){
							factor.clear(); topproduct = i*j;
						}
						factor.insert(two);
					}
				}
			}
		}
	}
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> grid[i][j];
			psaHor[i][j+1] = grid[i][j] + psaHor[i][j];
			psaVer[j][i+1] = grid[i][j] + psaVer[j][i];
		}
	}
	int out = 0;
	for(auto u: factor){
		if(u.first>u.second){
			for(int i = u.first; i<=h; i++){
				int temp = 0;
				for(int j = 0; j < w; j++){
					temp += (psaVer[j][i] - psaVer[j][i-u.first]);
					if(j>=u.second){
						temp -= (psaVer[j-u.second][i]-psaVer[j-u.second][i-u.first]);
					}
					out = max(temp,out);
				}
			}
		}
		else{
			for(int i = u.second; i<=w; i++){
				int temp = 0;
				for(int j = 0; j < h; j++){
					temp += (psaHor[j][i] - psaHor[j][i-u.second]);
					if(j>=u.first){
						temp -= (psaHor[j-u.first][i]-psaHor[j-u.first][i-u.second]);
					}
					out = max(temp,out);
				}
			}
		}
	}
	cout << out;
}