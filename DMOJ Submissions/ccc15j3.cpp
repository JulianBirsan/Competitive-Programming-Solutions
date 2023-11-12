#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	string out = "";

	unordered_map<char,bool> vow;
	vow['a'] = true;
	vow['e'] = true;
	vow['i'] = true;
	vow['o'] = true;
	vow['u'] = true;

	char l[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v',
			'w','x','y','z'
	};

	for(int i = 0; i < s.length(); i++){
		out += s[i];
		if(vow.count(s[i])==false){
			if(s[i]=='b' || s[i]=='c'){
				out += 'a';
			}
			else if(s[i]=='d' || s[i]=='f' || s[i]=='g'){
				out += 'e';
			}
			else if(s[i]=='h' || s[i] == 'j' || s[i] == 'l' || s[i] == 'k'){
				out += 'i';
			}
			else if(s[i] == 'm' || s[i] == 'n' || s[i]=='p' || s[i]=='q' || s[i]=='r'){
				out += 'o';
			}
			else{
				out += 'u';
			}
			if(s[i]=='z'){
				out += 'z';
			}
			else{
				for(int j = 0; j < 21; j++){
					if(l[j]==s[i]){
						out += l[j+1];
						break;
					}
				}
			}
		}
	}
	cout << out;
}