#include <bits/stdc++.h>

using namespace std;

int out = 0;

void sim(int g, int w, int tie1, int tie2, int t, vector<vector<int> > scores){
	if(w!=0){
		scores[w][0] += 3;
	}
	if(tie1!=0 || tie1!=0){
		scores[tie1][0]++; scores[tie2][0]++;
	}
	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <=4; j++){
			if(scores[i][j]==0){
				scores[i][j] = 1; scores[j][i] = 1;
				sim(g+1,0,i,j,t,scores);
				sim(g+1,i,0,0,t,scores);
				sim(g+1,j,0,0,t,scores);
			}
		}
	}
	if(g==6){
		int check = 0;
		for(int i = 1; i <= 4; i++){
			check += scores[i][0]<scores[t][0];
		}
		out += check==3;
	}
}

int main(){
	int t,g,a,b,sa,sb;
	cin >> t >> g;
	vector<vector<int> > scores;
	vector<int> temp;
	for(int i = 0; i <= 4; i++){
		temp.push_back(0);
	}
	for(int i = 0; i <= 4; i++){
		scores.push_back(temp);
		scores[i][i] = 1;
	}
	for(int i = 0; i < g; i++){
		cin >> a >> b >> sa >> sb;
		scores[a][b] = 1; scores[b][a] = 1;
		if(sa>sb){
			scores[a][0] += 3;
		}
		else if(sb>sa){
			scores[b][0] += 3;
		}
		else{
			scores[a][0]++; scores[b][0]++;
		}
	}
	sim(g,0,0,0,t,scores);
	cout << out;
}