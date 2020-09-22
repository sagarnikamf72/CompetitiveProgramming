#include<bits/stdc++.h>
#define debug(x) cerr << "[ " << #x << " : " << x << " ] ";

using namespace std;

void solve(){
	long long u, v;
	cin >> u >> v;
	if((u&1) != (v&1) || u > v) {
		cout << -1 << endl;
	}
	else if(u == v) {
		if(u != 0) cout << 1 << "\n" << u << endl;
		else cout << 0 << endl;
	}
	else{
		long long x = (v - u)/2;
		if(u&x){
			cout << 3 << "\n" << u << " " << x << " " << x << endl;
		}
		else{
			cout << 2 << "\n" << u+x << " " << x << endl;
		}
	}
}

int main(){
	int t = 1;
	//  cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
