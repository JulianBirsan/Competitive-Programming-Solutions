#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{

    int n;

    cin >> n;

    vector<int> x;
    vector<int> y;

    for(int i = 0; i <= n; i++){

        string cors;

        getline(cin,cors);

        int index = cors.find(",");

        if(index>0){

            string tx = cors.substr(0,index);
            string ty = cors.substr(index+1);

            int ttx = stoi(tx);
            x.push_back(ttx);

            int tty = stoi(ty);
            y.push_back(tty);
        }


    }

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    cout << x[0]-1 << "," << y[0] -1<<endl;
    cout << x.back()+1 << "," << y.back() + 1;

    return 0;

}