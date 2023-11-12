#include <bits/stdc++.h>

using namespace std;

int main() {
    int p;
    int n;
    int r;
    int c = 0;

    cin >> p;
    cin >> n;
    cin >> r;

    int tot = n;

    while(tot<=p){
        int a = tot;
        tot += n*r;
        n = tot-a;
        c += 1;
    }

    std::cout << c;
}