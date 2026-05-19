#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()


void so(int test){
	int n;
	cin >> n;
	vector<pair<int,int>> seg(n);
	for(auto &[a,b] :seg)
		cin >> a >> b;
	auto dis = [&](int id1, int id2)->ll{
		auto [x1,y1] = seg[id1];
		auto [x2,y2] = seg[id2];
		return (y2 - y1)*1ll*(y2 - y1) + (x2 - x1)*1ll*(x2 - x1);
	};
	vector<vector<int>> reach(n);
	ll ans = LLONG_MAX;
	forn(i,n){
		forn(j,n)if( i != j)
			reach[i].emplace_back(j);
		sort(all(reach[i]), [&](int id1, int id2){
				return dis(i,id1) < dis(i,id2);
				});
		ans = min(ans, dis(reach[i].back(), i));
	}
	forn(i,n){
		forn(id,n)if(i != id){
			ll ma = 0;
			int ele = 0;
			for(int ind = sz(reach[i]) - 1; ind >= 0; ind--){
				int id_cur = reach[i][ind];
				ma = max(dis(id,id_cur), ma);
				ele += (id_cur != id);
				ans = min(ans, 
		   (ind - 1 >= 0 ? dis(i, reach[i][ind-1]) : 1) + ma + (ele == 0));
			}
		}
	}
	cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}
