#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int

int main(){
    FastIO
    
    // Solution start here
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int& x : a) cin >> x;
        
        if (n == 1)
            cout << "1" <<"\n";
        else{
            int count = 1;
            for (int i=1; i<n; i++){
                if(a[i-1] >= a[i])
                    count++;
                else{
                    a[i] = a[i-1];
                }
            }
            cout << count << "\n";
        }
    }
    // solution end here

    return 0;
}