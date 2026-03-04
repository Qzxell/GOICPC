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

int cost[15][105][3];

void so(int test){
	int n,m,w;
	string s;
	cin >> n >> m >> w;
	forn(i,n){
		cin >> s;
		forn(j,m)
			cin >> cost[i][j][0] >> cost[i][j][1] >> cost[i][j][2];
	}
	ll ans = 0;
	forn(i,n){
		forn(j,n){// compra i , venta j
			if( i == j)continue;
			vii profit;
			forn(k,m){
				if(cost[j][k][1] - cost[i][k][0] <= 0)continue;
				int cnt = cost[i][k][2];
				int prof = cost[j][k][1] - cost[i][k][0];
				profit.push_back({prof,cnt});
			}
			sort(rall(profit));
			int dispo = w;
			ll ret = 0;
			for(auto [gan,cnt] : profit){
				if(cnt <= dispo){
					ret += gan*cnt;
					dispo -= cnt;
					continue;
				}
				ret += dispo*gan;
				dispo = 0;
			}
			ans = max(ans,ret);
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

