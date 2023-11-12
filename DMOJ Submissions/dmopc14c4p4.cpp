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

void output(string message, char code[]){
	string out = "";
	for(unsigned int i = 0; i < message.length(); i++){
		out += code[message[i]];
	}
	cout << out;
	exit(0);
}

int main(){
	string mes,temp;
	string goal = "HAILHYDRA";
	char tmp[26];
	int n;
	bool check = false;
	vector<int> indices;
	cin >> mes >> n;
	for(int i = 0; i < mes.length()-8; i++){
		if(mes[i]==mes[i+4]){
			if(mes[i+1]==mes[i+8]){
				if(mes[i+1]!=mes[i]){
					if(mes[i+1]!=mes[i+2]){
						if(mes[i+2]!=mes[i+3]){
							if(mes[i+3]!=mes[i+5]){
								if(mes[i+5]!=mes[i+6]){
									if(mes[i+6]!=mes[i+7]){
										indices.push_back(i);
										i+=7;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	char cd[100];
	for(int i = 0; i < n; i++){
		scanf("%26s",tmp);
		for(int j = 0; j < 26; j++){
			cd[tmp[j]] = j+65;
		}
		for(int j = 0; j < indices.size(); j++){
			string message = mes.substr(indices[j],9);
			bool chk = true;
			for(int k = 0; k < 9; k++){
				if(cd[message[k]]!=goal[k]){
					chk = false; break;
				}
			}
			if(chk) output(mes,cd);
		}
	}
	printf("KeyNotFoundError");
}