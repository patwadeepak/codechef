#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<int> vi;

int main(){
    FastIO
    
    int t; cin >> t;
	while(t--){
		string txt;
		cin >> txt;
		vector<char> deck;
		int count=0, prefix_length=0;

		for(int i=0; i<txt.length(); i++){
			if(txt[i]=='>')
			{
				if(deck.size() == 0){
					break;
				}
				else
					deck.pop_back();
					count+=2;
					if(deck.size()==0)
						prefix_length = count;
			}
			else{
				deck.push_back('<');
			}
		}

		cout << ((count>prefix_length) ? prefix_length : count) << "\n";
	}
}