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

const int N = 2e5 + 5;
int e[N],r[N],ord[N];
ll dp[N];

void so(int test){
	int n,m;
	cin >> n >> m;

	multiset<int> s;
	forn(i,n)
		cin >> e[i] >> r[i];
	iota(ord,ord+n, 0);
	sort(ord,ord+n, [](int id1 , int id2){
			return r[id1] > r[id2];
			});
	int ind = -1;
	ll mx = 0;
	ll sum = 0;
	for(int rad = n; rad >= 0 ;rad--){
		while(ind + 1 < n and r[ord[ind+1]] >= rad){
			ind++;
			s.insert(e[ord[ind]]);
			sum += e[ord[ind]];
		}
		while(sz(s) >= rad+1){
			auto it = s.begin();
			if(sz(s) == rad + 1)
				mx = max(mx,sum);
			sum -= *it;
			s.erase(it);
		}
		dp[rad] = sum;
		mx = max(mx,sum);
	}
	forsn(rad,1,n+1)
		dp[rad] = max(dp[rad], dp[rad-1] );
	forn(i,m){
		int x,y;
		cin >> x >> y;
		ll ans = max(mx, dp[y] + x);
		cout << ans << ' ';
	}
	cout << '\n';
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

