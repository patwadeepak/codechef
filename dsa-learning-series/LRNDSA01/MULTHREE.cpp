#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int

int main(){
    FastIO
    
    // solution start here
    int t;
    cin >> t;
    string pattern = "2486";
    while(t--){
        string result;
        ll k, d0, d1; cin>>k>>d0>>d1;
        
        // d    d0d1 d%10  pattern    i
        // 1   - 10  1   2486 2486 ...0
        // 2   - 11  2   4862 4862 ...1
        // 3   - 21  3   6248 6248 ...3
        // 4   - 31  4   8624 8624 ...2
        // 5   - 41  5   0000 0000 ...
        // 6   - 51  6   2486 2486 ...0
        // 7   - 61  7   4862 4862 ...1
        // 8   - 71  8   6248 6248 ...3
        // 9   - 81  9   8624 8624 ...2
        // 10  - 91  0   0000 0000 ...
        // 11  - 92  1   2486 2486 ...0
        // 12  - 93  2   4862 4862 ...1
        // 13  - 94  3   6248 6248 ...3
        // 14  - 95  4   8624 8624 ...2
        // 15  - 96  5   0000 0000 ...
        // 16  - 97  6   2486 2486 ...0
        // 17  - 98  7   4862 4862 ...1
        // 18  - 99  8   6248 6248 ...3

        int index[] = {0, 1, 3, 2};
        ll d = d0+d1;
        if(d%5==0){
            if((d+d%10)%3==0) result = "YES";
            else result = "NO";
        } 
        else{
            ll sum = 0 , times=(k-3)%4 , j = index[(d%5-1)];
            for(ll i=j ; i<j+times ; i++) sum += pattern[i%4]-'0';
            ll total = d+d%10;
            if (k > 2) total += ((k-3)/4)*20 + sum; 
            if(total%3 == 0) result = "YES";
            else result = "NO";
        }
        cout << result << "\n";
    }    
    // solution end here

    return 0;
}