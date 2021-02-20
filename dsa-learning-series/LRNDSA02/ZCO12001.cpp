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
    
    // 20
	// ( ) ( ( ) ) ( ) ( ( ) ( ) ) ( ( ) ( ) )
	// 1 2 1 1 2 2 1 2 1 1 2 1 2 2 1 1 2 1 2 2
	// 2 4 6 9
	
	int n; cin >> n;
	vector<int> a(n);
	for(auto &x : a) cin >> x;
	int curr_len=0, max_len=-1, max_len_start=0, curr_depth=0, max_depth=-1, first_open_index=0, max_deck_size=0, max_depth_start=-1;
	vector<int> deck;
	for(int i=0; i<n; i++){
		if(a[i] == 1){
			deck.push_back(a[i]);
			if(deck.size()==0)
				first_open_index = i;
			if(max_deck_size < deck.size()){
				max_deck_size = deck.size();
				max_depth_start = first_open_index;
			}
		}
		else{
			deck.pop_back();
			curr_len+=2;
			if(max_len < curr_len){
				max_len = curr_len;
				max_len_start = i - max_len + 1;
				curr_len=0;
			}
		}
	}
	cout<<max_deck_size<<" "<<max_depth_start<<" "<<max_len<<" "<<max_len_start;
}