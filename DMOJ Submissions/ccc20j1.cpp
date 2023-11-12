#include <bits/stdc++.h>

using namespace std;

int main() {
    int score = 0;

    int s;
    int m;
    int l;

    cin >> s;
    cin >> m;
    cin >> l;

    score += s + 2*m + 3*l;

    if(score >= 10){
        std::cout << "happy";
    }
    else{
        std::cout << "sad";
    }
}