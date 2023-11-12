#include <bits/stdc++.h>

using namespace std;

int main(){
	string s,t;
	cin >> s >> t;
	int x = s.length(); int y = t.length();
	int dpLen[x+1][y+1];
	for(int i = 0; i <= x; i++){
		for(int j = 0; j <= y; j++){
			if(i == 0 || j == 0){
				dpLen[i][j] = 0;
			}
			else{
				if(s[i-1]==t[j-1]){
					dpLen[i][j] = dpLen[i-1][j-1] + 1;
				}
				else{
					dpLen[i][j] = max(dpLen[i-1][j],dpLen[i][j-1]);
				}
			}
		}
	}
	string out = "";
	while(x>0 && y>0){
		if(s[x-1] == t[y-1]){
			out.insert(out.begin(),s[x-1]);
			x--; y--;
		}
		else{
			if(dpLen[x-1][y]>dpLen[x][y-1]){
				x--;
			}
			else{
				y--;
			}
		}
	}
	cout << out;
}