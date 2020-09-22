#include<bits/stdc++.h>
#define debug(x) cerr << "[ " << #x << " : " << x << " ] "

using namespace std;

const long long inf = 4e18;
long long ans;

long long sq(long long x){
	return 1ll*x*x;
}

void util(vector<long long> l, vector<long long> m, vector<long long> r){
	for(auto x : l){
		auto y = lower_bound(m.begin(), m.end(), x);
		auto z = upper_bound(r.begin(), r.end(), x);
		if(y == m.end() || z == r.begin()) continue;
		z--;
		ans = min(ans, sq(x - *y) + sq(*y - *z) + sq(*z - x));
	}
} 

void solve(){
	int nr, ng, nb;
	ans = inf;
	cin >> nr >> ng >> nb;
	vector<long long> vr(nr), vg(ng), vb(nb);
	for(auto& x : vr) cin >> x;
	for(auto& x : vg) cin >> x;
	for(auto& x : vb) cin >> x;
	
	sort(vr.begin(), vr.end());
	sort(vg.begin(), vg.end());
	sort(vb.begin(), vb.end());
	
	util(vr, vg, vb);util(vr, vb, vg);
	util(vg, vr, vb);util(vg, vb, vr);
	util(vb, vr, vg);util(vb, vg, vr);
	
	//  for(int i = 0; i < nr; i++) {
		//  long long tmp = 0, j[3], k[3];
		//  j[0] = lower_bound(vg.begin(), vg.end(), vr[i]) - vg.begin();
		//  j[1] = upper_bound(vg.begin(), vg.end(), vr[i]) - vg.begin();
		//  j[0] = min(ng - 1ll, j[0]);
		//  j[1] = min(ng - 1ll, j[1]);
		//  j[2] = max(j[0] - 1, 0ll);
		//  for(int l = 0; l < 3; l++){
			//  int c = (vr[i] + vg[j[l]] + 1)/2, f = (vr[i] + vg[j[l]])/2;
			//  k[0] = lower_bound(vb.begin(), vb.end(), c) - vb.begin();
			//  k[1] = upper_bound(vb.begin(), vb.end(), c) - vb.begin();
			//  k[0] = min(nb - 1ll, j[0]);
			//  k[1] = min(k[1], nb - 1ll);
			//  k[2] = max(k[0] - 1, 0ll);
			//  for(int m = 0; m < 3; m++) {
				//  long long x = vr[i], y = vg[j[l]], z = vb[k[m]];
				//  tmp = ((x - y)*(x - y) + (y - z)*(y - z) + (z - x)*(z - x));
				//  debug(i); debug(j[l]); debug(k[m]); debug(tmp) << endl;
				//  ans = min(ans, tmp);
			//  }
			
			
			//  k[0] = lower_bound(vb.begin(), vb.end(), f) - vb.begin();
			//  k[1] = upper_bound(vb.begin(), vb.end(), f) - vb.begin();
			//  k[0] = min(nb - 1ll, j[0]);
			//  k[1] = min(k[1], nb - 1ll);
			//  k[2] = max(k[0] - 1, 0ll);
			//  for(int m = 0; m < 3; m++) {
				//  long long x = vr[i], y = vg[j[l]], z = vb[k[m]];
				//  tmp = ((x - y)*(x - y) + (y - z)*(y - z) + (z - x)*(z - x));
				//  debug(i); debug(j[l]); debug(k[m]); debug(tmp) << endl;
				//  ans = min(ans, tmp);
			//  }
		//  }
	//  }
	cout << ans << endl;
}

int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
