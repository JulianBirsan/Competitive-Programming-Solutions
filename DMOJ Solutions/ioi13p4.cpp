#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool done[5005];

// const int MAXN = 5001;
// int doorsOpened[MAXN];
// int placement[MAXN];
// int state[MAXN];
// int N;
// int numTries = 0;
 
// void answer(int S[], int D[]) {
    // for(int i=0;i<N;i++){
        // cout<<D[i]<<" ";
    // }
    // cout<<"\n";
    // for(int i=0;i<N;i++){
        // cout<<S[i]<<" ";
    // }
    // cout<<"\n";
    // for (int a = 0; a < N; a++) {
        // if (S[a] != state[a] || D[a] != placement[a]) {
            // printf("INCORRECT TRY USING %i TRIES\n", numTries);
            // exit(0);
        // }
    // }
    // printf("ANSWER CORRECT USING %i TRIES\n", numTries);
    // exit(0);
// }
 
 
// int tryCombination(int S[]) {
    // std::fill(doorsOpened, doorsOpened + MAXN, 0);
//  
    // for (int a = 0; a < N; a++) {
        // //printf("%i ", S[a]);
        // doorsOpened[placement[a]] = (S[a] == state[a]);
    // }
    // //printf("\n");
    // for (int a = 0; a < N; a++) {
        // //printf("%i ", doorsOpened[a]);
    // }
    // //printf("\n");
//  
    // numTries++;
    // for (int a = 0; a < N; a++) {
        // if (!doorsOpened[a]) {
            // //printf("ret @ %i\n", a);
            // return a;
        // }
    // }
    // //printf("ret >%i\n", N);
    // return -1;
// }

void exploreCave(int N){
    int arr[N];
    int pos[N];
    int n=N;
    for(int i=0;i<N;i++){
        
        int l=0,r=n-1;
        
        for(int j=0;j<n;j++){
            if(!done[j]) arr[j]=0;
        }
        bool up=0;
        int first=tryCombination(arr);
        if(first>i || first==-1) up=true;
        
        for(int j=0;j<n;j++){
            if(!done[j]) arr[j]=!up;
        }
        
        // cout<<up<<"\n";
        
        int ans=-1;
        
        while(l<=r){
            int mid=(l+r)>>1;
            for(int j=l;j<=mid;j++){
                if(!done[j]) arr[j]=up;
            }
            int tmpl=l;
            // for(int j=0;j<N;j++) cout<<arr[j]<<" ";
            // cout<<"\n";
            // cout<<l<<"->"<<mid<<" "<<tryCombination(arr)<<"\n";
            if(tryCombination(arr)==i) r=mid-1,ans=mid;
            else l=mid+1;
            for(int j=tmpl;j<=mid;j++){
                if(!done[j]) arr[j]=!up;
            }
        }
        done[ans]=true;
        arr[ans]=!up;
        pos[ans]=i;
        // cout<<ans<<"\n\n";
    }
    answer(arr,pos);
}


// int main(){
    // scanf("%i", &N);
    // for (int a = 0; a < N; a++) {
        // scanf("%i", &placement[a]); //enter order of switches from 0...N - 1
    // }
    // for (int a = 0; a < N; a++) {
        // scanf("%i", &state[a]); //please only enter 1 or 0 here, otherwise you screw yourself up
    // }
    // exploreCave(N);
    // printf("Your program forgot to call answer(int S[], int D[])");
// }