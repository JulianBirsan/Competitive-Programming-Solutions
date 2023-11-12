#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int h = 0;
	int m = 0;
	string t;
	cin >> t;
	h += (t[0]-48)*10 + t[1]-48;
	m += (t[3]-48)*10 + t[4]-48;
	m += 60*h;

	int dist = 240;

	while(dist>0){
		if((m>=420 && m<600) || (m>=900 && m<1140)){
			dist--;
		}
		else{
			dist-=2;
		}
		m++;
	}

	m = m%1440;
	int hour = m/60;
	int minute = m-60*hour;

	string out = "";

	if(hour<10){
		out+="0";
	}
	out += to_string(hour);
	out += ":";

	if(minute<10){
		out+="0";
	}
	out += to_string(minute);
	cout << out;
}