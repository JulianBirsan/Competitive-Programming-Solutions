#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;


int main()
{

    string aro;

    getline(cin,aro);

    vector<int> nums;

    int tot = 0;

    for(unsigned int i = 0; i < aro.size(); i++){

        if (aro.at(i) == 'I'){
            nums.push_back(1);
        }
        else if (aro.at(i) == 'V'){
            nums.push_back(5);
        }
        else if (aro[i] == 'X'){
            nums.push_back(10);
        }
        else if (aro[i] == 'L'){
            nums.push_back(50);
        }
        else if (aro[i] =='C'){
            nums.push_back(100);
        }
        else if (aro[i] =='D'){
            nums.push_back(500);
        }
        else if (aro[i] =='M'){
            nums.push_back(1000);
        }
        else{
            int x;
            x = aro[i] - 48;
            nums.push_back(x);

        }
    }

    for(unsigned int i = 1; i < nums.size(); i+=2){
        if(nums[i] < nums[i+2]){
            nums[i] = -nums[i];
        }

        tot += nums[i-1]*nums[i];

    }



    cout << tot;

    return 0;
}