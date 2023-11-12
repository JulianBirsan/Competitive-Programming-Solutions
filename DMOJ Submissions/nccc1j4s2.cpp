#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,xint;
	bool reduced = true; bool latin = true;
	char x;
	string str;
	unordered_set<char> nums;
	vector<unordered_set<int> > track;
	nums.insert('0'); nums.insert('1'); nums.insert('2'); nums.insert('3'); nums.insert('4');
	nums.insert('5'); nums.insert('6'); nums.insert('7'); nums.insert('8'); nums.insert('9');
	cin >> n;
	for(int i = 0; i < n; i++){
		unordered_set<int> temp;
		track.push_back(temp);
	}
	int topr[n];
	int leftc[n];
	for(int i = 0; i < n; i++){
		unordered_set<int> s;
		cin >> str;
		for(int j = 0; j < n; j++){
			x = str[j];
			if(nums.count(x)==1){
				xint = x-48;
			}
			else{
				xint = x-55;
			}
			if(s.count(xint)==1){
				latin = false;
			}
			if(track[j].count(xint)==1){
				latin = false;
			}
			s.insert(xint);
			if(i==0){
				topr[j] = xint;
			}
			if(j==0){
				leftc[i] = xint;
			}
		}
	}
	for(int i = 1; i < n; i++){
		if(leftc[i]<leftc[i-1] || topr[i]<topr[i-1]){
			reduced = false;
			break;
		}
	}
	if(latin){
		if(reduced){
			cout << "Reduced\n";
		}
		else{
			cout << "Latin\n";
		}
	}
	else{
		cout << "No\n";
	}
}