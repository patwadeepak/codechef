#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    FastIO
    
    // Solution start here
    int t;
    cin >> t;
    while(t--){
        string x;
        cin >> x;
        bool isNotZero = false;
        for(int i=x.length()-1; i >= 0; i--) {
            if (isNotZero)
                cout << x[i];
            else
            {
                if(x[i] != '0'){
                    isNotZero = true;
                    cout << x[i];
                }
            }
        }
        cout << "\n";
    }
    
    // solution end here

    return 0;
}