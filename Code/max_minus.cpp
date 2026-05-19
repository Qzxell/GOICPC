#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

const int N = 2e5 + 5;
int v[N];
int mi_pref[N];
int mx_pref[N];
int mi_suf[N];
int mx_suf[N];

int n;
int solve(){
	int mi = (1<<30);
	int ma = -(mi);
	int l = -1,r;

	forsn(i,1,n+ 1){
		mi = min(mi, v[i]);
		ma = max(ma, v[i]);
	}
	forsn(i,1,n+1) if( v[i] == mi){
		if(l == -1)
			l = i;
		r = i;
	}
	int caj = 0;
	forsn(i,l,r+1)
		caj = max(caj, v[i] - mi);

	mi_pref[0] = (1<<30);
	mi_suf[n+1] = (1<<30);
	mx_pref[0] = -(1<<30);
	mx_suf[n+1] = -(1<<30);

	forsn(i,1,n+ 1){
		mi_pref[i] = min(mi_pref[i-1] , v[i]);
		mx_pref[i] = max(mx_pref[i-1] , v[i]);
	}
	for(int i = n ; i >= 1; i--){
		mx_suf[i] = max(mx_suf[i+1], v[i]);
		mi_suf[i] = min(mi_suf[i+1], v[i]);
	}
	int lo = -1,lf = ma - mi, mid;
	//cout <<'\t'<< lf << '\n';

	auto f = [&](int dis)->bool{
		if(caj > dis)return false;
		int l_c = l;
		int r_c = r;
		while( r_c + 1 <= n && v[r_c + 1] - mi <= dis)
			r_c++;
		while( l_c - 1 >= 1 && v[l_c - 1] - mi <= dis)
			l_c--;
		int c_mx_pr = mx_pref[l_c-1];
		int c_mi_pr = mi_pref[l_c-1];
		int c_mx_sf = mx_suf[r_c+1];
		int c_mi_sf = mi_suf[r_c+1];
		return max(c_mx_pr,c_mx_sf) - min(c_mi_pr,c_mi_sf) <= dis;
	};

	while( lf - lo > 1){
		mid = (lo + lf)>>1;
		if(f(mid)) lf = mid;
		else lo = mid;
	}
	return lf;
}
void so(int test){
	cin >> n;

	forsn(i,1,n+ 1)
		cin >> v[i];
	int ans = solve();
	forsn(i,1,n+ 1)
		v[i] *= -1;
	ans = min(ans,solve());
	cout << ans << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

