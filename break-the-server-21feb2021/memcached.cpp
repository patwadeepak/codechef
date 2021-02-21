#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<int> vi;

void solve(){
    int n; cin >> n;
    bool running = false, error = false;
    for(int i=0; i<n; i++){
        string command; cin >> command;
        if (command == "start"){
            running = true;
        }
        else if (command=="restart"){
            running = true;
        }
        else{
            if(running==false){
                error = true;
                break;
            }
            else running = false;
        }
    }
    if(error) cout << "404\n";
    else cout << "200\n";

}

int main(){
    FastIO
    int t; cin >> t;
    while(t--) solve();    
}