#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	int out = 0;
	int group = 1;
	char prev = '.';

	for(int i = 0; i < n; i++){
		string stu;
		cin >> stu;
		out++;
		if(tolower(stu[0])==prev){
			group++;
		}
		else{
			out += group*(group-1)/2;
			group = 1;
		}
		out = out % 1000000007;
		prev = tolower(stu[0]);
	}
	out += group*(group-1)/2;
	cout << out % 1000000007;
}