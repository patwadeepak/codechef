#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int

int main(){
    FastIO
    
    // solution start here
    int t;
    cin >> t;
    while(t--){
        int laddu = 0;
        int activities; string origin;
        cin >> activities >> origin;
        while(activities--){
            string activity; cin >> activity;
            if(activity[8] == 'W'){
                int rank; cin >> rank;
                int value = rank>20 ? 0 : 20-rank;
                laddu += 300 + value;
            }
            else if(activity[8] == 'R')
                laddu += 300;
            else if (activity[8] == 'D'){
                int severity; cin >> severity;
                laddu += severity;
            }
            else
                laddu += 50;
        }
        int k = 200;
        if (origin[0] != 'I') k = 400;
        cout << laddu/k << "\n";
    }    
    // solution end here

    return 0;
}