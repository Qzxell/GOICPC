#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

void so(int test){
	int n;
	cin >> n;
	vi v(n);
	forn(i,n) cin >> v[i];
	vii pun;
	vii ori;
	forsn(i,1,n-1)if(v[i-1] < v[i] && v[i] > v[i+1]){
		pun.push_back({v[i],i});
		ori.push_back({i,v[i]});
	}
	sort(rall(pun));
	if(sz(pun) == 0){
		cout << 0 << '\n';
		return;
	}
	if(sz(pun) == 1){
		int ind = pun[0].se;
		int co1 = 0,co2 = 0;
		forsn(i,ind,n)
			co1 += v[i] < v[ind];
		forsn(i,0,ind)
			co2 += v[i] < v[ind];
		cout << min(co1,co2) << '\n';
		return;
	}
	int ind1,ind2;
	ind1 = min(pun[0].se,pun[1].se);
	ind2 = max(pun[0].se,pun[1].se);
	int ans = 0;
	forsn(i,ind2,n)
		ans += v[i] < v[ind2];
	forsn(i,0,ind1)
		ans += v[i] < v[ind1];
	int f1,f2;
	// ori : cord in v , eleme
	f1 = lower_bound(all(ori),make_pair(ind1,-1)) - ori.begin();
	f2 = lower_bound(all(ori),make_pair(ind2,-1)) - ori.begin();
	if(f1 + 1 == f2){
		cout << ans << '\n';
		return;
	}
	int mi = 0;
	forsn(i,f1,f2){
		mi = max(mi,1 + ori[i+1].fi - ori[i].fi);
	}
	ans = ans + ind2 - ind1 - mi;
	auto solve = [&]()->{
		vi picos;
		int prev = -1;
		for(auto [ind,va] : ord){
			if(va > prev){
				prev = va;
				picos.push_back(ind);
			}
		}
		int fi_ind = picos[0];
		int ret = 0;
		for(int i = 0 ; i < fi_ind ;i++){
			if(v[i] < v[fi_ind])
				ret++;
		}
		for(int i = 0 ; i < sz(picos);i++){
			int id = picos[i];
			int nex = (i+1 < sz(picos) ? picos[i+1] : n);
			for(int j = id; j < nex;j++){
				if(v[j] < v[id])
					ret++;
			}
		}
		return ret;
	};
	auto solve1 = [&]()->{
		vi picos;
		int prev = -1;
		reverse(all(ord));
		for(auto [ind,va] : ord){
			if(va > prev){
				prev = va;
				picos.push_back(ind);
			}
		}
		int fi_ind = picos[0];
		int ret = 0;
		for(int i = n-1 ; i > fi_ind ;i--){
			if(v[i] < v[fi_ind])
				ret++;
		}
		for(int i = 0 ; i < sz(picos);i++){
			int id = picos[i];
			int nex = (i+1 < sz(picos) ? picos[i+1] : n);
			for(int j = id; j < nex;j++){
				if(v[j] < v[id])
					ret++;
			}
		}
		return ret;
	};
	ans = min(solve(),ans);
	ans = min(solve1(),ans);
	cout << ans << '\n';
	//cout << ans + ind2 - ind1 - mi << '\n';
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

