#include<bits/stdc++.h>
#define debug(x) cerr << "[ " << #x << " : " << x << " ] ";
#define debugP(x) cerr << "[ " << x.second << " : " << x.first << " ] ";

using namespace std;

bool cmp(pair<int, int>& f, pair<int, int>& s) {
	if(f.first == s.first) {
		return f.second > s.second;
	}
	else {
		return f.first < s.first;
	}
}

void solve() {
	int n, a[10];
	vector<pair<int, int> > v; 
	cin >> n;
	for(int i = 1; i < 10; i++) {
		cin >> a[i];
		v.push_back({a[i], i});
	}
	
	sort(v.begin(), v.end(), cmp);
	for(auto x : v) debugP(x);
	cerr << endl;
	
	string ans = "";
	while(n >= v[0].first) {
		ans += ('0' + v[0].second);
		n -= v[0].first;
	}
	int curr = 0;
	while(n) {
		bool flag = true;
		debug(curr);
		cerr << endl;
		for(int dig = 9; dig > v[0].second; dig--) {
			if(v[0].first + n >= a[dig]) {
				ans[curr] = ('0' + dig);
				debug(ans[curr]);
				cerr << endl;
				n -= (a[dig] - v[0].first);
				flag = false;
				curr++;
				break;
			}
		}
		if(flag || curr >= (int)ans.length()) n = 0;
	}
	
	if(ans == "") {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
}

int main(){
	int t = 1;
	//  cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
//  898207
//  99745 99746 99748 99752 99760 99776 99808 99872 100000
