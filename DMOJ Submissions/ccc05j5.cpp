#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string w;
	cin >> w;
	while(w!="X"){
		int it = w.length();
		int b = 0;
		int s = 0;
		char prev = 'N';
		string out = "YES";
		for(int i = 0; i < it; i++){
			if(w[i]=='B'){
				b++;
				if(prev=='A' || prev=='S'){
					out = "NO";
					break;
				}
			}
			else if(w[i]=='S'){
				s++;
				if(s>b){
					out = "NO";
					break;
				}
				if(prev=='N' || prev == 'B'){
					out = "NO";
					break;
				}
			}
			else if(w[i]=='N'){
				if(prev=='B' || prev== 'N'){
					out = "NO";
					break;
				}
			}
			else if(w[i]=='A'){
				if(prev=='A' || prev=='S'){
					out = "NO";
					break;
				}
			}
			else{
				out = "NO";
				break;
			}
			prev = w[i];
		}
		if(b!=s){
			out = "NO";
		}
		if(prev=='N' || prev =='B'){
			out = "NO";
		}
		cout << out << "\n";
		cin >> w;
	}
}