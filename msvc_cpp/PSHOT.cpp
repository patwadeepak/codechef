#include <iostream>
#include <vector>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){
    FastIO
    // solution start here
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int a=0, b=0, result=2*n, a_left=n, b_left=n;
        for (int i=0; i<2*n;i++){
            if(i%2==0) {
                a += s[i]-'0';
                a_left--;
            }
            else {
                b += s[i]-'0';
                b_left--;
            }
            if ((a+a_left < b) || (a > b+b_left))
            {
                result = i+1;
                break;
            }
        }
        cout << result << "\n";
    }

    // solution end here
    return 0;
}