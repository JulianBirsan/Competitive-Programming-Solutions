#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{

    int n;
    int d;

    cin >> n;
    cin >> d;

    d = abs(d);

    vector<int> intervals;
    vector<int> jumps;

    int it = 0;

    do{
        int x;
        cin >> x;
        intervals.push_back(x);
        it++;
    }
    while(it < n);

    for(unsigned int i = 0; i < intervals.size(); i++){

        if(d/intervals[i] * intervals[i] == d){
                jumps.push_back(d/intervals[i]);
        }
    }

    if(jumps.size() == 0){
        cout << "This is not the best time for a trip.";
    }

    else{
        sort(jumps.begin(),jumps.end());
        cout << jumps[0];
    }

    return 0;

}