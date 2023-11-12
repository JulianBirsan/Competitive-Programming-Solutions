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
#define MAXLOG 26

int grid[7][7];

pii find4ver(){
	pii ans=make_pair(-1,-1);
	for(int i=0;i<3;i++){
		for(int j=0;j<6;j++){
			if(grid[i][j]!=0&&grid[i+1][j]!=0&&grid[i+2][j]!=0&&grid[i+3][j]!=0){
				return make_pair(i,i+3);
			}
		}
	}
	return ans;
}

void ver4(pii cor){
	int low=min(cor.first,cor.second);
	int high=max(cor.first,cor.second);
	for(int j=0;j<5;j++){
		if(grid[low][j]!=0&&grid[high][j]!=0&&grid[high-1][j]){
			for(int i=low;i<=high;i++){
				for(int k=low;k<=high;k++){
					if(grid[i][j-1]!=0&&grid[k][j+1]!=0){
						if(grid[i][j-1]==1){
							cout<<grid[k][j+1]<<"\n";
							exit(0);
						}
						else if(grid[k][j+1]==1){
							cout<<grid[i][j-1]<<"\n";
							exit(0);
						}
						else if(grid[high][j]==1){
							cout<<grid[high-2][j]<<"\n";
							exit(0);
						}
						else if(grid[high-1][j]==1){
							cout<<grid[high-3][j]<<"\n";
							exit(0);
						}
						else if(grid[high-2][j]==1){
							cout<<grid[high][j]<<"\n";
							exit(0);
						}
						else if(grid[high-3][j]==1){
							cout<<grid[high-1][j]<<"\n";
							exit(0);
						}
					}
				}
			}
		}
	}
}


pii find3ver(){
	pii ans=make_pair(-1,-1);
	for(int i=0;i<4;i++){
		for(int j=0;j<6;j++){
			if(grid[i][j]!=0&&grid[i+1][j]!=0&&grid[i+2][j]!=0){
				return make_pair(i,i+2);
			}
		}
	}
	return ans;
}

void ver3(pii cor){
	int low=min(cor.first,cor.second);
	int high=max(cor.first,cor.second);
	for(int j=0;j<6;j++){
		if(grid[low][j]!=0&&grid[low+1][j]!=0&&grid[high][j]!=0){
			if(low>0){
				if(grid[low][j-1]!=0&&grid[low-1][j-1]!=0){
					for(int i=low;i<=high;i++){
						if(grid[i][j+1]!=0){
							if(grid[i][j+1]==1||grid[low][j-1]==1){
								cout<<max(grid[i][j+1],grid[low][j-1])<<"\n";
								exit(0);
							}
							if(grid[low-1][j-1]==1||grid[high][j]==1){
								cout<<max(grid[low-1][j-1],grid[low+1][j])<<"\n";
								exit(0);
							}
							cout<<max(grid[low][j],grid[high][j])<<"\n";
							exit(0);
						}
					}
				}
				if(grid[low][j+1]!=0&&grid[low-1][j+1]!=0){
					for(int i=low;i<=high;i++){
						if(grid[i][j-1]!=0){
							if(grid[i][j-1]==1||grid[low][j+1]==1){
								cout<<max(grid[i][j-1],grid[low][j+1])<<"\n";
								exit(0);
							}
							if(grid[low-1][j+1]==1||grid[high][j]==1){
								cout<<max(grid[low-1][j+1],grid[low+1][j])<<"\n";
								exit(0);
							}
							cout<<max(grid[low][j],grid[high][j])<<"\n";
							exit(0);
						}
					}
				}
			}
			if(grid[high][j-1]!=0&&grid[high+1][j-1]!=0){
				for(int i=low;i<=high;i++){
					if(grid[i][j+1]!=0){
						if(grid[i][j+1]==1||grid[high][j-1]==1){
							cout<<max(grid[i][j+1],grid[high][j-1])<<"\n";
							exit(0);
						}
						if(grid[high+1][j-1]==1||grid[high][j]==1){
							cout<<max(grid[high+1][j-1],grid[low+1][j])<<"\n";
							exit(0);
						}
						cout<<max(grid[high][j],grid[low][j])<<"\n";
						exit(0);
					}
				}
			}
			if(grid[high][j+1]!=0&&grid[high+1][j+1]!=0){
				for(int i=low;i<=high;i++){
					if(grid[i][j-1]!=0){
						if(grid[i][j-1]==1||grid[high][j+1]==1){
							cout<<max(grid[i][j-1],grid[high][j+1])<<"\n";
							exit(0);
						}
						if(grid[high+1][j+1]==1||grid[low][j]==1){
							cout<<max(grid[high+1][j+1],grid[high-1][j])<<"\n";
							exit(0);
						}
						cout<<max(grid[high][j],grid[low][j])<<"\n";
						exit(0);
					}
				}
			}
			if(low>1){
				if(grid[low][j-1]!=0&&grid[low-1][j-1]!=0&&grid[low-2][j-1]!=0){
					if(grid[low][j-1]==1||grid[low-2][j-1]==1){
						cout<<max(grid[low][j-1],grid[low-2][j-1])<<"\n";
						exit(0);
					}
					if(grid[low-1][j-1]==1||grid[low+1][j]==1){
						cout<<max(grid[low-1][j-1],grid[low+1][j])<<"\n";
						exit(0);
					}
					cout<<max(grid[high][j],grid[low][j])<<"\n";
					exit(0);
				}
				if(grid[low][j+1]!=0&&grid[low-1][j+1]!=0&&grid[low-2][j+1]!=0){
					if(grid[low][j-1]==1||grid[low-2][j-1]==1){
						cout<<max(grid[low][j+1],grid[low-2][j+1])<<"\n";
						exit(0);
					}
					if(grid[low-1][j-1]==1||grid[low+1][j]==1){
						cout<<max(grid[low-1][j+1],grid[low+1][j])<<"\n";
						exit(0);
					}
					cout<<max(grid[high][j],grid[low][j])<<"\n";
					exit(0);
				}
			}
			if(high<6){
				if(grid[high][j-1]!=0&&grid[high+1][j-1]!=0&&grid[high+2][j-1]!=0){
					if(grid[high][j-1]==1||grid[high+2][j-1]==1){
						cout<<max(grid[high][j-1],grid[high+2][j-1])<<"\n";
						exit(0);
					}
					if(grid[high+1][j-1]==1||grid[high-1][j]==1){
						cout<<max(grid[high+1][j-1],grid[high-1][j])<<"\n";
						exit(0);
					}
					cout<<max(grid[high][j],grid[low][j])<<"\n";
					exit(0);
				}
				if(grid[high][j+1]!=0&&grid[high+1][j+1]!=0&&grid[high+2][j+1]!=0){
					if(grid[high][j+1]==1||grid[high+2][j+1]==1){
						cout<<max(grid[high][j+1],grid[high+2][j+1])<<"\n";
						exit(0);
					}
					if(grid[high+1][j+1]==1||grid[high-1][j]==1){
						cout<<max(grid[high+1][j+1],grid[high-1][j])<<"\n";
						exit(0);
					}
					cout<<max(grid[high][j],grid[low][j])<<"\n";
					exit(0);
				}
			}
		}
	}
}

void find2ver(){
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(grid[i][j]!=0&&grid[i+1][j]!=0){
				if(j>1&&i>1){
					if(grid[i][j-1]!=0&&grid[i-1][j-1]!=0&&grid[i-1][j-2]!=0&&grid[i-2][j-2]!=0){
						if(grid[i+1][j]==1||grid[i-1][j-1]==1){
							cout<<max(grid[i+1][j],grid[i-1][j-1])<<"\n";
							exit(0);
						}
						if(grid[i][j]==1||grid[i-1][j-2]==1){
							cout<<max(grid[i][j],grid[i-1][j-2])<<"\n";
							exit(0);
						}
						cout<<max(grid[i-2][j-2],grid[i][j-1])<<"\n";
						exit(0);
					}
				}
				if(j>1&&i<6){
					if(grid[i][j-1]!=0&&grid[i+1][j-1]!=0&&grid[i+2][j-2]!=0&&grid[i+3][j-2]!=0){
						if(grid[i][j]==1||grid[i+2][j-1]==1){
							cout<<max(grid[i+1][j],grid[i+2][j-1])<<"\n";
							exit(0);
						}
						if(grid[i+1][j]==1||grid[i+2][j-2]==1){
							cout<<max(grid[i+1][j],grid[i+2][j-2])<<"\n";
							exit(0);
						}
						cout<<max(grid[i+3][j-2],grid[i+1][j-1])<<"\n";
						exit(0);
					}
				}
				if(j<6&&i>1){
					if(grid[i][j+1]!=0&&grid[i-1][j+1]!=0&&grid[i-1][j+2]!=0&&grid[i-2][j+2]!=0){
						if(grid[i][j+1]==1||grid[i-2][j+2]==1){
							cout<<max(grid[i][j+1],grid[i-2][j+2])<<"\n";
							exit(0);
						}
						if(grid[i][j]==1&&grid[i-1][j+2]==1){
							cout<<max(grid[i][j],grid[i-1][j+2])<<"\n";
							exit(0);
						}
						cout<<max(grid[i+1][j],grid[i-1][j+1])<<"\n";
						exit(0);
					}
				}
				if(j<6&&i<6){
					if(grid[i+1][j+1]!=0&&grid[i+2][j+1]!=0&&grid[i+2][j+1]!=0&&grid[i+3][j+2]!=0){
						if(grid[i][j]==1||grid[i+2][j+1]==1){
							cout<<max(grid[i][j],grid[i+2][j+1])<<"\n";
							exit(0);
						}
						if(grid[i+1][j]==1||grid[i+2][j+2]==1){
							cout<<max(grid[i+1][j],grid[i+2][j+2])<<"\n";
							exit(0);
						}
						cout<<max(grid[i+1][j+1],grid[i+3][j+2])<<"\n";
						exit(0);
					}
				}
				return;
			}
		}
	}
}

void find2hor(){
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(grid[j][i]!=0&&grid[j][i+1]!=0){
				if(i>1&&j>1){
					if(grid[j-1][i]!=0&&grid[j-1][i-1]!=0&&grid[j-2][i-1]!=0&&grid[j-2][i-2]!=0){
						if(grid[j][i+1]==1||grid[j-1][i-1]==1){
							cout<<max(grid[j][i+1],grid[j-1][i-1])<<"\n";
							exit(0);
						}
						if(grid[j][i]==1||grid[j-2][i-1]==1){
							cout<<max(grid[i][j],grid[i-1][j-2])<<"\n";
							exit(0);
						}
						cout<<max(grid[j-2][i-2],grid[j-1][i])<<"\n";
						exit(0);
					}
				}
				if(i>1&&j<6){
					if(grid[j-1][i]!=0&&grid[j-1][i+1]!=0&&grid[j-2][i+2]!=0&&grid[j-2][i+3]!=0){
						if(grid[j][i]==1||grid[j-1][i+2]==1){
							cout<<max(grid[j][i+1],grid[j-1][i+2])<<"\n";
							exit(0);
						}
						if(grid[j][i+1]==1||grid[j-2][i+2]==1){
							cout<<max(grid[j][i+1],grid[j-2][i+2])<<"\n";
							exit(0);
						}
						cout<<max(grid[j-2][i+3],grid[j-1][i+1])<<"\n";
						exit(0);
					}
				}
				if(i<6&&j>1){
					if(grid[j][i+1]!=0&&grid[j+1][i-1]!=0&&grid[j+2][i-1]!=0&&grid[j+2][i-2]!=0){
						if(grid[j+1][i]==1||grid[j+2][i-2]==1){
							cout<<max(grid[j+1][i],grid[j+2][i-2])<<"\n";
							exit(0);
						}
						if(grid[j][i]==1&&grid[j+2][i-1]==1){
							cout<<max(grid[j][i],grid[j+2][i-1])<<"\n";
							exit(0);
						}
						cout<<max(grid[j][i+1],grid[j+1][i-1])<<"\n";
						exit(0);
					}
				}
				if(j<6&&i<6){
					if(grid[j+1][i+1]!=0&&grid[j+1][i+2]!=0&&grid[j+1][i+2]!=0&&grid[j+2][i+3]!=0){
						if(grid[j][i]==1||grid[j+1][i+2]==1){
							cout<<max(grid[j][i],grid[j+1][i+2])<<"\n";
							exit(0);
						}
						if(grid[j][i+1]==1||grid[j+2][i+2]==1){
							cout<<max(grid[j][i+1],grid[j+2][i+2])<<"\n";
							exit(0);
						}
						cout<<max(grid[j+1][i+1],grid[j+2][i+3])<<"\n";
						exit(0);
					}
				}
				return;
			}
		}
	}
}

void rotateMatrix()
{
    for (int x = 0; x < 7 / 2; x++) {
        for (int y = x; y < 7 - x - 1; y++) {
            int temp = grid[x][y];
            grid[x][y] = grid[y][7 - 1 - x];
            grid[y][7 - 1 - x]  = grid[7 - 1 - x][7 - 1 - y];
            grid[7 - 1 - x][7 - 1 - y] = grid[7 - 1 - y][x];
            grid[7 - 1 - y][x] = temp;
        }
    }
}
void solve(){
	if(find4ver()!=make_pair(-1,-1)){
		ver4(find4ver());
	}
	else if(find3ver()!=make_pair(-1,-1)){
		ver3(find3ver());
	}
	find2ver();
	find2hor();
}

int main(){
	memset(grid,0,sizeof(grid));
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			cin>>grid[i][j];
		}
	}
	solve();
	rotateMatrix();
	solve();
	rotateMatrix();
	solve();
	rotateMatrix();
	solve();
	cout<<0<<"\n";
}